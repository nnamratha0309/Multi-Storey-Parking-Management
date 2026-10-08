#include <stdio.h>
#include <string.h>
#include "parking.h"

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
    int found = 0;

    printf("\nEnter vehicle registration number: ");
    scanf("%19s", registrationNumber);

    // Check if the vehicle is already parked
    for (int i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicles[i].registrationNumber, registrationNumber) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Vehicle is already parked!\n");
        return;
    }

    // Search floors sequentially
    for (int i = 0; i < FLOORS; i++)
    {
        // Search slots sequentially
        for (int j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (parking[i][j] == 0)
            {
                // Mark slot as occupied
                parking[i][j] = 1;

                // Store vehicle details
                strcpy(vehicles[vehicleCount].registrationNumber,
                       registrationNumber);

                vehicles[vehicleCount].floor = i + 1;
                vehicles[vehicleCount].slot = j + 1;

                vehicleCount++;

                printf("\nVehicle parked successfully!\n");
                printf("Floor : %d\n", i + 1);
                printf("Slot  : %d\n", j + 1);

                return;
            }
        }
    }

    printf("\nSorry! Parking is full.\n");
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
            {
                printf("Slot %d : Empty\n", j + 1);
            }
            else
            {
                printf("Slot %d : Occupied\n", j + 1);
            }
        }
    }

    printf("\n====================================\n");
}
void searchVehicle()
{
    char registrationNumber[20];

    printf("\nEnter vehicle registration number to search: ");
    scanf("%19s", registrationNumber);

    for (int i = 0; i < vehicleCount; i++)
    {
        if (strcmp(vehicles[i].registrationNumber, registrationNumber) == 0)
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