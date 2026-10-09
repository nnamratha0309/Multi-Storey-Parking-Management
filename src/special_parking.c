
#include <stdio.h>
#include <string.h>
#include "special_parking.h"

int reservedParking[FLOORS][SLOTS_PER_FLOOR];

void initializeReservedSlots(void)
{
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            reservedParking[i][j] = 0;
        }
    }

    // Reserve Floor 1, Slots 1 and 2
    reservedParking[0][0] = 1;
    reservedParking[0][1] = 1;
}

void displayReservedSlots(void)
{
    printf("\n========== RESERVED SLOTS ==========\n");

    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (reservedParking[i][j] == 1)
            {
                printf("Floor %d, Slot %d: Reserved\n",
                       i + 1, j + 1);
            }
        }
    }

    printf("====================================\n");
}

void parkSpecialVehicle(void)
{
    char registrationNumber[20];

    printf("\nEnter special vehicle registration number: ");

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

    if (vehicleCount >= MAX_VEHICLES)
    {
        printf("Parking area is full!\n");
        return;
    }

    // Special vehicles use reserved slots first
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (reservedParking[i][j] == 1 &&
                parking[i][j] == 0)
            {
                parking[i][j] = 1;

                strcpy(vehicles[vehicleCount].registrationNumber,
                       registrationNumber);
                vehicles[vehicleCount].floor = i + 1;
                vehicles[vehicleCount].slot = j + 1;
                vehicleCount++;

                printf("\nSpecial vehicle parked successfully!\n");
                printf("Floor: %d\n", i + 1);
                printf("Slot : %d\n", j + 1);
                return;
            }
        }
    }

    printf("\nNo reserved slots are available.\n");
}

void exitVehicle(void)
{
    char registrationNumber[20];

    printf("\nEnter vehicle registration number to exit: ");

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
            int floor = vehicles[i].floor;
            int slot = vehicles[i].slot;

            parking[floor - 1][slot - 1] = 0;

            for (int j = i; j < vehicleCount - 1; j++)
            {
                vehicles[j] = vehicles[j + 1];
            }

            vehicleCount--;

            printf("\nVehicle exited successfully!\n");
            printf("Floor %d, Slot %d is now available.\n",
                   floor, slot);
            return;
        }
    }

    printf("\nVehicle not found in the parking area.\n");
}
