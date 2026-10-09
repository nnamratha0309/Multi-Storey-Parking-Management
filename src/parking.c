
#include <stdio.h>
#include <string.h>
#include "parking.h"
#include "priority.h"

int parking[FLOORS][SLOTS_PER_FLOOR];
Vehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void initializeParking()
{
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            parking[i][j] = 0;
        }
    }

    vehicleCount = 0;
}

void parkVehicle()
{
    char registrationNumber[20];

    printf("\nEnter vehicle registration number: ");

    if (scanf("%19s", registrationNumber) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    // Check whether the vehicle is already parked
    for (int i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicles[i].registrationNumber,
                   registrationNumber) == 0)
        {
            printf("\nVehicle is already parked!\n");
            return;
        }
    }

    // Scenario 4: Handle full parking
    if (isParkingFull() || vehicleCount >= MAX_VEHICLES)
    {
        printf("\nSorry! Parking is full.\n");
        printf("No slots are currently available.\n");
        return;
    }

    // Scenario 3: Allocate the lowest available floor and slot
    int floor = findPriorityFloor();

    if (floor == -1)
    {
        printf("\nSorry! Parking is full.\n");
        return;
    }

    int slot = findPrioritySlot(floor);

    if (slot == -1)
    {
        printf("\nNo available slot on the selected floor.\n");
        return;
    }

    // Mark the slot as occupied
    parking[floor - 1][slot - 1] = 1;

    // Store vehicle details
    strcpy(vehicles[vehicleCount].registrationNumber,
           registrationNumber);

    vehicles[vehicleCount].floor = floor;
    vehicles[vehicleCount].slot = slot;

    vehicleCount++;

    printf("\nVehicle parked successfully!\n");
    printf("Registration Number : %s\n", registrationNumber);
    printf("Floor               : %d\n", floor);
    printf("Slot                : %d\n", slot);
}

void displayParkingStatus()
{
    printf("\n========== PARKING STATUS ==========\n");

    for (int i = 0; i < FLOORS; i++)
    {
        printf("\nFloor %d:\n", i + 1);

        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (parking[i][j] == 0)
                printf("Slot %d : Empty\n", j + 1);
            else
                printf("Slot %d : Occupied\n", j + 1);
        }
    }

    printf("\n====================================\n");
}

void searchVehicle()
{
    char registrationNumber[20];

    printf("\nEnter vehicle registration number to search: ");

    if (scanf("%19s", registrationNumber) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicles[i].registrationNumber,
                   registrationNumber) == 0)
        {
            printf("\nVehicle found!\n");
            printf("Registration Number : %s\n",
                   vehicles[i].registrationNumber);
            printf("Floor               : %d\n",
                   vehicles[i].floor);
            printf("Slot                : %d\n",
                   vehicles[i].slot);
            return;
        }
    }

    printf("\nVehicle not found in the parking area.\n");
}
