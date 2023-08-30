#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUM_COMPONENTS 12
#define NUM_CONTROL_RODS 16

// Define reactor components and variables
typedef struct {
    char name[50];
    double temperature; // in Celsius
    double xenonLevel; // in ppm
    double neutronPopulation; // in neutrons
    double neutronDensity; // in neutrons/cm^3
    double flowRate; // in m^3/s
    double microSvRate; // in µSv/h
    double coolant; // in m^3
    double mw; // in Mw/h
} Component;

typedef struct {
    double fuelLoad;
    char fuelType[50];
    Component components[NUM_COMPONENTS];
} Reactor;

// Initialize reactor with default values
Reactor initReactor() {
    Reactor reactor;
    reactor.fuelLoad = 130.0; // Default fuel load
    strcpy(reactor.fuelType, "Thorium"); // Default fuel type is Thorium

     // Initialize other components and properties
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        strcpy(reactor.components[i].name, "Component");
        reactor.components[i].temperature = 300.0; // Initial temperature in Celsius
        reactor.components[i].xenonLevel = 0.0;   // Initial xenon level in ppm
        reactor.components[i].neutronPopulation = 1.0e6; // Initial neutron population
        reactor.components[i].neutronDensity = 8.0e11;   // Initial neutron density in neutrons/cm^3
        reactor.components[i].flowRate = 10.0;   // Initial flow rate in m^3/s
        reactor.components[i].microSvRate = 2.0; // Initial micro Sv rate in µSv/h
        reactor.components[i].coolant = 7800.0; // Initial coolant in m^3
        reactor.components[i].mw = 1287.3;         // Initial megawatts output
    }

    return reactor;
}

// Function to reset reactor components during a SCRAM event
void scramReactor(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].temperature = 23.1;
        reactor->components[i].xenonLevel = 0.0;
        reactor->components[i].neutronPopulation = 0.0;
        reactor->components[i].neutronDensity = 0.0;
        reactor->components[i].flowRate += (20.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (3.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw = 0.0;
    }
}
    
// Function to adjust properties for uranium fuel
void adjustPropertiesForUranium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += (1.5e6 * (1 + (rand() % 3 - 1) * 0.01)); // Adding a +/- 1% variation
        reactor->components[i].neutronDensity += (1.2e12 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].flowRate += (20.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (3.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].coolant += (7800 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw *= reactor->components[i].temperature * reactor->components[i].flowRate;
    }
}

// Function to adjust properties for thorium fuel
void adjustPropertiesForThorium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += (1.2e6 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].neutronDensity += (1.0e12 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].flowRate += (15.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (2.5 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].coolant += (7800 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw *= reactor->components[i].temperature * reactor->components[i].flowRate;
    }
}

// Function to adjust properties for lead-210 fuel
void adjustPropertiesForLead210(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += (1.3e6 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].neutronDensity += (1.1e12 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].flowRate += (18.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (2.7 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].coolant += (7800 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw *= reactor->components[i].temperature * reactor->components[i].flowRate;
    }
}

// Function to adjust properties for plutonium fuel
void adjustPropertiesForPlutonium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += (1.8e6 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].neutronDensity += (1.4e12 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].flowRate += (25.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (3.5 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].coolant += (7800 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw *= reactor->components[i].temperature * reactor->components[i].flowRate;
    }
}

// Function to adjust properties for radium fuel
void adjustPropertiesForRadium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += (1.0e6 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].neutronDensity += (0.8e12 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].flowRate += (10.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].microSvRate += (2.0 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].coolant += (7800 * (1 + (rand() % 3 - 1) * 0.01));
        reactor->components[i].mw *= reactor->components[i].temperature * reactor->components[i].flowRate;
    }
}

// Function to simulate reactor behavior for a time step
void simulateTimeStep(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        // Introduce small temperature fluctuations
        reactor->components[i].temperature += (rand() % 4 - 2) * 0.01; // Fluctuating by +/- 0.01 °C

        // Update xenon levels (example: increase by 0.01 ppm per time step)
        reactor->components[i].xenonLevel += 0.01;

        // Add more behavior simulation here
    }
}

// Function to change reactor's fuel load and type
void changeFuelLoad(Reactor *reactor, double newFuelLoad, const char *newFuelType) {
    reactor->fuelLoad = newFuelLoad;
    strcpy(reactor->fuelType, newFuelType);

    // Adjust reactor components based on new fuel
    if (strcmp(newFuelType, "Uranium") == 0) {
        adjustPropertiesForUranium(reactor);
    } else if (strcmp(newFuelType, "Thorium") == 0) {
        adjustPropertiesForThorium(reactor);
    } else if (strcmp(newFuelType, "Radium") == 0) {
        adjustPropertiesForRadium(reactor);
    } else if (strcmp(newFuelType, "Lead-210") == 0) {
        adjustPropertiesForLead210(reactor);
    } else if (strcmp(newFuelType, "Plutonium") == 0) {
        adjustPropertiesForPlutonium(reactor);
    }
    // Add other fuel types here if I feel like I need to
}

void printCommonProperties(Reactor *reactor) {
    Component *commonComponent = &reactor->components[0];
    printf("Common Component Properties:\n");
    printf(" - Temperature: %.2f °C\n", commonComponent->temperature);
    printf(" - Xenon Level: %.2f ppm\n", commonComponent->xenonLevel);
    printf(" - Neutron Population: %.2e neutrons\n", commonComponent->neutronPopulation);
    printf(" - Neutron Density: %.2e neutrons/cm^3\n", commonComponent->neutronDensity);
    printf(" - Flow Rate: %.2f m^3/s\n", commonComponent->flowRate);
    printf(" - Micro Sv Rate: %.2f µSv/h\n", commonComponent->microSvRate);
    printf(" - Coolant Meters: %.2f m^3\n", commonComponent->coolant);
    printf(" - Megawatts Output: %.2f Mw/h\n", commonComponent->mw);
}

// Function to print the ASCII drawing of the control rod positions
void printControlRods(double controlRodPositions[NUM_CONTROL_RODS]) {
    printf("\nControl Rod Positions:\n");

    for (int i = 0; i < NUM_CONTROL_RODS; i++) {
        int position = (int)round(controlRodPositions[i] * 100);
        printf("| %3d ", position);
    }

    printf("|\n");
    printf("|");
    for (int i = 0; i < NUM_CONTROL_RODS; i++) {
        printf("-----");
    }
    printf("|\n");
    printf("|");
    for (int i = 0; i < NUM_CONTROL_RODS; i++) {
        printf("  %2d ", i + 1);
    }
    printf("|\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Reactor reactor = initReactor();
    double controlRodPositions[NUM_CONTROL_RODS];

    printf("BWR Reactor Simulator - PQAR\n");
    printf("Licenced PQAR Open-Source, read .lic file\n");
    
     for (int i = 0; i < NUM_CONTROL_RODS; i++) {
        controlRodPositions[i] = (rand() % 101) / 100.0; // Initialize control rod positions
    }

    while (1) {
        char command[50];
        printf("Enter a command ('help' for command list): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting simulator.\n");
            break;
        } else if (strcmp(command, "changeFuel") == 0) {
            double newFuelLoad;
            char newFuelType[50];
            printf("Enter new fuel load: ");
            scanf("%lf", &newFuelLoad);
            printf("Enter new fuel type (Uranium, Thorium, Radium, Lead-210, Plutonium): ");
            scanf("%s", newFuelType);
            changeFuelLoad(&reactor, newFuelLoad, newFuelType);
            printf("Fuel load changed.\n");
        } else if (strcmp(command, "simulate") == 0) {
            simulateTimeStep(&reactor);
            printf("Simulation complete.\n");
        } else if (strcmp(command, "status") == 0) {
            printf("Reactor Status:\n");
            printf("Fuel Load: %.2f kg\n", reactor.fuelLoad);
            printCommonProperties(&reactor);
            printControlRods(controlRodPositions);
        } else if (strcmp(command, "scram") == 0) {
            scramReactor(&reactor);
            printf("Reactor SCRAMMED.\n");
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf(" - exit\n");
            printf(" - changeFuel\n");
            printf(" - simulate\n");
            printf(" - status\n");
            printf(" - scram\n");
            printf(" Note: If reactor SCRAM, cannot go critical anymore\n");
        } else {
            printf("Unknown command. Type 'help' for command list.\n");
        }
    }

    return 0;
}