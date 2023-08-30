#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_COMPONENTS 12

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
    // ...

    return reactor;
}

// Function to adjust properties for uranium fuel
void adjustPropertiesForUranium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += 1.5e6;
        reactor->components[i].neutronDensity += 1.2e12;
        reactor->components[i].flowRate += 20.0;
        reactor->components[i].microSvRate += 3.0;
        reactor->components[i].coolant += 7800;
        reactor->components[i].mw *= reactor->components[i].neutronPopulation * reactor->components[i].neutronDensity * reactor->components[i].microSvRate;
    }
}

// Function to adjust properties for thorium fuel
void adjustPropertiesForThorium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += 1.2e6;
        reactor->components[i].neutronDensity += 1.0e12;
        reactor->components[i].flowRate += 15.0;
        reactor->components[i].microSvRate += 2.5;
        reactor->components[i].coolant += 7800;
        reactor->components[i].mw *= reactor->components[i].neutronPopulation * reactor->components[i].neutronDensity * reactor->components[i].microSvRate;
    }
}

// Function to adjust properties for radium fuel
void adjustPropertiesForRadium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += 1.0e6;
        reactor->components[i].neutronDensity += 0.8e12;
        reactor->components[i].flowRate += 10.0;
        reactor->components[i].microSvRate += 2.0;
        reactor->components[i].coolant += 7800;
        reactor->components[i].mw *= reactor->components[i].neutronPopulation * reactor->components[i].neutronDensity * reactor->components[i].microSvRate;
    }
}

// Function to adjust properties for lead-210 fuel
void adjustPropertiesForLead210(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += 1.3e6;
        reactor->components[i].neutronDensity += 1.1e12;
        reactor->components[i].flowRate += 18.0;
        reactor->components[i].microSvRate += 2.7;
        reactor->components[i].coolant += 7800;
        reactor->components[i].mw *= reactor->components[i].neutronPopulation * reactor->components[i].neutronDensity * reactor->components[i].microSvRate;
    }
}

// Function to adjust properties for plutonium fuel
void adjustPropertiesForPlutonium(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        reactor->components[i].neutronPopulation += 1.8e6;
        reactor->components[i].neutronDensity += 1.4e12;
        reactor->components[i].flowRate += 25.0;
        reactor->components[i].microSvRate += 3.5;
        reactor->components[i].coolant += 7800;
        reactor->components[i].mw *= reactor->components[i].neutronPopulation * reactor->components[i].neutronDensity * reactor->components[i].microSvRate;
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

void printComponentStatus(Component *component) {
    printf("%s:\n", component->name);
    printf(" - Temperature: %.2f °C\n", component->temperature);
    printf(" - Xenon Level: %.2f ppm\n", component->xenonLevel);
    printf(" - Neutron Population: %.2e neutrons\n", component->neutronPopulation);
    printf(" - Neutron Density: %.2e neutrons/cm^3\n", component->neutronDensity);
    printf(" - Flow Rate: %.2f m^3/s\n", component->flowRate);
    printf(" - Micro Sv Rate: %.2f µSv/h\n", component->microSvRate);
    printf(" - Coolant Meters: %.2f m^3\n", component->coolant);
    printf(" - Megawatts Output: %.2f Mw/h\n", component->mw);
}

// Function to simulate reactor behavior for a time step
void simulateTimeStep(Reactor *reactor) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        // Simulate behavior of each component
        // Add this later
    }
}

int main() {
    Reactor reactor = initReactor();

    printf("BWR Reactor Simulator - PQAR\n");
    printf("Copyright 2023 PQAR\n");

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
            for (int i = 0; i < NUM_COMPONENTS; i++) {
                printComponentStatus(&reactor.components[i]);
                printf(" - Temperature: %.2f °C\n", reactor.components[i].temperature);
                printf(" - Xenon Level: %.2f ppm\n", reactor.components[i].xenonLevel);
                printf(" - Neutron Population: %.2e neutrons\n", reactor.components[i].neutronPopulation);
                printf(" - Neutron Density: %.2e neutrons/cm^3\n", reactor.components[i].neutronDensity);
                printf(" - Flow Rate: %.2f m^3/s\n", reactor.components[i].flowRate);
                printf(" - Micro Sv Rate: %.2f µSv/h\n", reactor.components[i].microSvRate);
                printf(" - Coolant Meters: %.2f m^3\n", reactor.components[i].coolant);
                printf(" - Megawatts Output: %.2f Mw/h\n", reactor.components[i].mw);
            }
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf(" - exit\n");
            printf(" - changeFuel\n");
            printf(" - simulate\n");
            printf(" - status\n");
        } else {
            printf("Unknown command. Type 'help' for command list.\n");
        }
    }

    return 0;
}
