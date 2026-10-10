
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
    int foundSlot = 0;

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

    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (reservedParking[i][j] == 1 &&
                parking[i][j] == 0)
            {
                foundSlot = 1;
                break;
            }
        }

        if (foundSlot)
        {
            break;
        }
    }

    if (!foundSlot)
    {
        printf("\nNo reserved slots are available.\n");
        return;
    }

    if (vehicleCount >= MAX_VEHICLES)
    {
        printf("\nParking area is full!\n");
        return;
    }

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
                printf("Registration Number : %s\n", registrationNumber);
                printf("Floor               : %d\n", i + 1);
                printf("Slot                : %d\n", j + 1);
                return;
            }
        }
    }
}
