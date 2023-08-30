# BWR Reactor Simulator
Welcome to the BWR Reactor Simulator, a text-based simulation tool designed to provide insights into the behavior of a Boiling Water Reactor (BWR) under various conditions and fuel types.

## Overview
The BWR Reactor Simulator offers an interactive platform to engage with a simplified simulation of a BWR reactor. With this simulator, you can experiment with different fuel types, adjust fuel loads, and observe how the reactor's components behave over time.

## Features
Fuel Load and Type: Explore diverse reactor scenarios by changing the reactor's fuel load and fuel type.
Behavior Simulation: Simulate the dynamic behavior of reactor components across various time steps.
Real-time Status: Monitor the current status of the reactor, including critical parameters such as temperature, xenon levels, neutron population, neutron density, flow rate, and micro Sv rate.
Usage
Follow these steps to start using the BWR Reactor Simulator:

Clone or Download: Obtain the simulator by cloning or downloading the repository to your local machine.
Compilation: Utilize a C compiler (such as gcc) to compile the source code.
Compilation 2: You can also look at the releases to get our reactor_simulator pre-compiled file for Linux.
Commands to install:
gcc main.c -o reactor_simulator -lm
(Note: The -lm flag is used to link the math library.)
Run the Simulator: Execute the compiled executable to launch the simulator using:
./reactor_simulator
Permission Error: Please refer to the Permissions section of this readme
Interact: Follow the prompts displayed on-screen to interact with the simulator and explore its capabilities.

## Permissions
Once the simulator has been downloaded, the permissions (Linux Machines) may not allow execution of the file,
to fix this, follow the steps listed below for Linux Machines:
Open a terminal window.
Navigate to the directory where your reactor_simulator executable is located using the cd command. 
For example, if the executable is in your home directory, you can navigate there using:
cd ~
Once you're in the correct directory, use the ls -l command to list the files and their permissions. 
Verify that the reactor_simulator file is listed and that it doesn't have the execute permission for the user. It might look something like this:
-rw-r--r-- 1 user user 1234567 Aug 29 10:00 reactor_simulator
To grant execute permission to the user, use the chmod command:
chmod +x reactor_simulator
This command adds the execute permission for the user.
Verify the permissions again using ls -l. You should now see an "x" in the user's permission column, indicating execute permission:
-rwxr--r-- 1 user user 1234567 Aug 29 10:00 reactor_simulator
Now, you should be able to run the program using:
./reactor_simulator

## Commands
The following commands are available for interacting with the simulator:

changeFuel: Modify the fuel load and type of the reactor to observe the resulting changes.
simulate: Initiate a simulation of the reactor's behavior over a single time step.
status: Access the present status of the reactor and its individual components.
exit: Terminate the simulator and exit the program.
scram: SCRAM the reactor to shut down operations.
help: Get commands list.


## Customization
Feel free to customize and adapt the simulator to suit your specific requirements. If you make any modifications or derivative works based on this simulator, ensure that you adhere to the terms outlined in the PQAR Open-Source License, which is included within the repository (.lic file).

## License
The BWR Reactor Simulator is distributed under the terms of the PQAR Open-Source License. You can find detailed information about the licensing terms in the provided LICENSE (.lic) file.

## Disclaimer
It is important to note that this simulator is intended solely for educational and informational purposes. The outcomes produced by the simulator may not accurately mirror real-world conditions. The original author, PQAR, assumes no liability for any potential damages that may arise from the use of this software.

## Contact
For any questions, feedback, or inquiries, please don't hesitate to contact us at [sapinyio@proton.me].

[PQAR]
[2023]
[pqar.net]
