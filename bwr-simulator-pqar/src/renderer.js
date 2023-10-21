const { ipcRenderer } = require('electron');

const changeFuelButton = document.getElementById('changeFuelButton');
const simulateButton = document.getElementById('simulateButton');
const scramButton = document.getElementById('scramButton');
const statusOutput = document.getElementById('statusOutput');

changeFuelButton.addEventListener('click', () => {
    ipcRenderer.send('changeFuel');
});

simulateButton.addEventListener('click', () => {
    ipcRenderer.send('simulate');
});

scramButton.addEventListener('click', () => {
    ipcRenderer.send('scram');
});

ipcRenderer.on('updateStatus', (event, status) => {
    statusOutput.textContent = status;
});
