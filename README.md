# BWR Reactor Simulator

Welcome to the BWR Reactor Simulator, a text-based simulation tool designed to provide insights into the behavior of a Boiling Water Reactor (BWR) under various conditions and fuel types. In the releases tab, there are 32bit exe, 64bit exe, and Linux applications for the program.

## Overview

The BWR Reactor Simulator offers an interactive platform to engage with a simplified simulation of a BWR reactor. With this simulator, you can experiment with different fuel types, adjust fuel loads, and observe how the reactor's components behave over time.

## Features

- **Fuel Load and Type:** Explore diverse reactor scenarios by changing the reactor's fuel load and fuel type.
- **Behavior Simulation:** Simulate the dynamic behavior of reactor components across various time steps.
- **Real-time Status:** Monitor the current status of the reactor, including critical parameters such as temperature, xenon levels, neutron population, neutron density, flow rate, and micro Sv rate.

## Usage

Follow these steps to start using the BWR Reactor Simulator:

1. **Clone or Download:** Obtain the simulator by cloning or downloading the repository to your local machine.
2. **Compilation:** Utilize a C compiler (such as gcc) to compile the source code.
    ```bash
    gcc main.c -o reactor_simulator.out -lm
    ```
    (Note: The `-lm` flag is used to link the math library.)
3. **Run the Simulator:** Execute the compiled executable to launch the simulator using:
    ```bash
    ./reactor_simulator
    ```
4. **Permission Error:** Please refer to the Permissions section of this readme.
5. **Interact:** Follow the prompts displayed on-screen to interact with the simulator and explore its capabilities.

## Permissions (For Linux Machines)

Once the simulator has been downloaded, the permissions may not allow execution of the file. To fix this, follow the steps listed below for Linux Machines:

1. Open a terminal window.
2. Navigate to the directory where your `reactor_simulator` executable is located using the `cd` command.
3. Verify the permissions using the `ls -l` command.
4. Grant execute permission to the user using the `chmod +x` command.
5. Verify the permissions again using `ls -l`.
6. Now, you should be able to run the program using `./reactor_simulator`.

## Commands

The following commands are available for interacting with the simulator:

- `changeFuel`: Modify the fuel load and type of the reactor to observe the resulting changes.
- `simulate`: Initiate a simulation of the reactor's behavior over a single time step.
- `status`: Access the present status of the reactor and its individual components.
- `exit`: Terminate the simulator and exit the program.
- `scram`: SCRAM the reactor to shut down operations.
- `help`: Get commands list.

## Customization

Feel free to customize and adapt the simulator to suit your specific requirements. If you make any modifications or derivative works based on this simulator, ensure that you adhere to the terms outlined in the PQAR Open-Source License, which is included within the repository (`.lic` file).

## License

The BWR Reactor Simulator is distributed under the terms of the PQAR Open-Source License. You can find detailed information about the licensing terms in the provided `LICENSE` (`.lic`) file. PQAR is using JENDL 5 rescourses for this simulation, and PQAR Experimentation records.

## Disclaimer

This simulator is for trained professionals, PQAR, Or other authorized users ONLY. You must have some Bash knowledge and BWR knowledge to be able to successfully install, execute, and use this program.
This simulator is intended solely for educational and informational purposes. The outcomes produced by the simulator may not accurately mirror real-world conditions. The original author, PQAR, assumes no liability for any potential damages that may arise from the use of this software.

## Contact

For any questions, feedback, or inquiries, please don't hesitate to contact us at [sapinyio@proton.me](mailto:sapinyio@proton.me).

[PQAR](https://pqar.net) [JENDL](https://wwwndc.jaea.go.jp/jendl/jendl.html) [2023]
