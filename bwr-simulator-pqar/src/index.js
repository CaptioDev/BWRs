const { app, BrowserWindow, ipcMain } = require('electron');
const { spawn } = require('child_process');
const path = require('path');

let mainWindow;

function createWindow() {
    mainWindow = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    });

    mainWindow.loadFile('index.html');

    // Handle window close event
    mainWindow.on('closed', () => {
        mainWindow = null;
    });

    // Handle IPC events from renderer process
    ipcMain.on('executeCommand', (event, command) => {
        // Spawn a child process to run the main.c program
        const childProcess = spawn('gcc', [path.resolve(__dirname, 'main.c'), '-o', 'main'], {
            cwd: '/workspaces/BWRs/bwr-simulator-pqar'
        });

        // Handle errors, if any, during compilation
        childProcess.stderr.on('data', (data) => {
            console.error(`Compilation Error: ${data}`);
            event.sender.send('commandOutput', { error: data.toString() });
        });

        // Handle successful compilation and execute the program
        childProcess.on('close', (code) => {
            if (code === 0) {
                const simulatorProcess = spawn(path.resolve(__dirname, 'main'), [], {
                    cwd: '/workspaces/BWRs/bwr-simulator-pqar'
                });

                simulatorProcess.stdout.on('data', (data) => {
                    event.sender.send('commandOutput', { output: data.toString() });
                });

                simulatorProcess.stderr.on('data', (data) => {
                    console.error(`Simulation Error: ${data}`);
                    event.sender.send('commandOutput', { error: data.toString() });
                });

                simulatorProcess.on('close', (code) => {
                    console.log(`Simulation Process exited with code ${code}`);
                    event.sender.send('commandExit', code);
                });
            } else {
                event.sender.send('commandOutput', { error: 'Compilation Error' });
            }
        });
    });
}

app.on('ready', createWindow);

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (mainWindow === null) {
        createWindow();
    }
});
