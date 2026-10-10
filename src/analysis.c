#include <stdio.h>
#include "analysis.h"
#include "special_parking.h"


void displayOccupancyAnalysis(void)
{
    int i, j;
    int occupied, available, reserved;
    int totalOccupied = 0;
    int totalAvailable = 0;
    int totalReserved = 0;
    int totalSlots = FLOORS * SLOTS_PER_FLOOR;

    printf("\n========== OCCUPANCY ANALYSIS ==========\n");

    for (i = 0; i < FLOORS; i++)
    {
        occupied = 0;
        available = 0;
        reserved = 0;

        for (j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (parking[i][j] != 0)
            {
                occupied++;
            }
            else if (reservedParking[i][j] == 1)
            {
                reserved++;
            }
            else
            {
                available++;
            }
        }

        totalOccupied += occupied;
        totalAvailable += available;
        totalReserved += reserved;

        printf("\nFloor %d\n", i + 1);
        printf("Occupied Slots       : %d\n", occupied);
        printf("Available Regular Slots: %d\n", available);
        printf("Reserved Slots       : %d\n", reserved);
        printf("Occupancy            : %.1f%%\n",
               occupied * 100.0 / SLOTS_PER_FLOOR);
    }

    printf("\nTotal Parking Slots       : %d\n", totalSlots);
    printf("Total Occupied            : %d\n", totalOccupied);
    printf("Total Available Regular   : %d\n", totalAvailable);
    printf("Total Reserved            : %d\n", totalReserved);
    printf("Overall Occupancy         : %.1f%%\n",
           totalOccupied * 100.0 / totalSlots);
}



void guideToAvailableSlot(void)
{
    int i, j;

    printf("\n========== AVAILABLE SLOT GUIDANCE ==========\n");

    for (i = 0; i < FLOORS; i++)
    {
        for (j = 0; j < SLOTS_PER_FLOOR; j++)
        {
            if (parking[i][j] == 0 &&
                reservedParking[i][j] == 0)
            {
                printf("Available parking slot found!\n");
                printf("Floor: %d\n", i + 1);
                printf("Slot : %d\n", j + 1);
                printf("Please proceed to Floor %d, Slot %d.\n",
                       i + 1, j + 1);
                return;
            }
        }
    }

    printf("Sorry! No regular parking slots are available.\n");
}

