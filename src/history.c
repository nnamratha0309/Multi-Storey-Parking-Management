#include <stdio.h>
#include <string.h>
#include "history.h"

Vehicle parkingHistory[MAX_HISTORY];
int historyCount = 0;

void initializeHistory(void)
{
    historyCount = 0;
}

void displayActiveVehicles(void)
{
    int i;

    printf("\n========== ACTIVE VEHICLES ==========\n");

    if (vehicleCount == 0)
    {
        printf("No vehicles are currently parked.\n");
        return;
    }

    for (i = 0; i < vehicleCount; i++)
    {
        printf("%d. Registration: %s | Floor: %d | Slot: %d\n",
               i + 1,
               vehicles[i].registrationNumber,
               vehicles[i].floor,
               vehicles[i].slot);
    }
}

void displayParkingHistory(void)
{
    int i;

    printf("\n========== PARKING HISTORY ==========\n");

    if (historyCount == 0)
    {
        printf("No exited vehicles in history.\n");
        return;
    }

    for (i = 0; i < historyCount; i++)
    {
        printf("%d. Registration: %s | Previous Floor: %d | Previous Slot: %d\n",
               i + 1,
               parkingHistory[i].registrationNumber,
               parkingHistory[i].floor,
               parkingHistory[i].slot);
    }
}

void exitVehicle(void)
{
    char registrationNumber[20];
    int i, j;

    printf("\nEnter registration number of exiting vehicle: ");
    scanf("%19s", registrationNumber);

    for (i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicles[i].registrationNumber,
                   registrationNumber) == 0)
        {
            if (historyCount < MAX_HISTORY)
            {
                parkingHistory[historyCount] = vehicles[i];
                historyCount++;
            }
            else
            {
                printf("Warning: Parking history is full; this exit won't be recorded.\n");
            }

            parking[vehicles[i].floor - 1][vehicles[i].slot - 1] = 0;

            printf("\nVehicle exited successfully!\n");
            printf("Freed Floor: %d, Slot: %d\n",
                   vehicles[i].floor, vehicles[i].slot);

            for (j = i; j < vehicleCount - 1; j++)
            {
                vehicles[j] = vehicles[j + 1];
            }

            vehicleCount--;
            return;
        }
    }

    printf("\nVehicle not found in active parking.\n");
}
