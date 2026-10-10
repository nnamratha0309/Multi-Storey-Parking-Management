
#include <stdio.h>
#include <string.h>
#include "parking.h"
#include "priority.h"
#include "special_parking.h"

int parking[FLOORS][SLOTS_PER_FLOOR];
Vehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void initializeParking(void)
{
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            parking[i][j] = 0;
        }
    }

    vehicleCount = 0;
    initializeReservedSlots();
}

void parkVehicle(void)
{
    char registrationNumber[20];

    printf("\nEnter vehicle registration number: ");

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
            printf("Vehicle is already parked!\n");
            return;
        }
    }

    if (vehicleCount >= MAX_VEHICLES || isParkingFull())
    {
        printf("\nSorry! Parking is full.\n");
        return;
    }

    int floor = findPriorityFloor();
    if (floor == -1)
    {
        printf("\nSorry! No regular parking slots are available.\n");
        return;
    }

    int slot = findPrioritySlot(floor);
    if (slot == -1)
    {
        printf("\nNo available slot on the selected floor.\n");
        return;
    }

    parking[floor - 1][slot - 1] = 1;

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

void displayParkingStatus(void)
{
    printf("\n========== PARKING STATUS ==========\n");

    for (int i = 0; i < FLOORS; i++)
    {
        printf("\nFloor %d:\n", i + 1);

        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (parking[i][j] == 1)
            {
                printf("Slot %d : Occupied\n", j + 1);
            }
            else if (reservedParking[i][j] == 1)
            {
                printf("Slot %d : Reserved\n", j + 1);
            }
            else
            {
                printf("Slot %d : Empty\n", j + 1);
            }
        }
    }

    printf("\n====================================\n");
}

void searchVehicle(void)
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
