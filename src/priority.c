
#include <stdio.h>
#include "priority.h"
#include "special_parking.h"

int getAvailableSlots(int floor)
{
    if (floor < 1 || floor > FLOORS)
    {
        return 0;
    }

    int count = 0;

    for (int j = 0; j < SLOTS_PER_FLOOR; j++)
    {
        if (parking[floor - 1][j] == 0 &&
            reservedParking[floor - 1][j] == 0)
        {
            count++;
        }
    }

    return count;
}

int isFloorFull(int floor)
{
    return getAvailableSlots(floor) == 0;
}

int isParkingFull(void)
{
    for (int i = 1; i <= FLOORS; i++)
    {
        if (!isFloorFull(i))
        {
            return 0;
        }
    }

    return 1;
}

int findPriorityFloor(void)
{
    for (int i = 1; i <= FLOORS; i++)
    {
        if (!isFloorFull(i))
        {
            return i;
        }
    }

    return -1;
}

int findPrioritySlot(int floor)
{
    if (floor < 1 || floor > FLOORS)
    {
        return -1;
    }

    for (int j = 0; j < SLOTS_PER_FLOOR; j++)
    {
        if (parking[floor - 1][j] == 0 &&
            reservedParking[floor - 1][j] == 0)
        {
            return j + 1;
        }
    }

    return -1;
}

void displayAvailableSlots(void)
{
    printf("\n========== AVAILABLE SLOTS ==========\n");

    for (int i = 1; i <= FLOORS; i++)
    {
        printf("Floor %d : %d regular slot(s) available\n",
               i, getAvailableSlots(i));
    }

    printf("=====================================\n");
}

void displayAllocationSequence(void)
{
    printf("\n======= ALLOCATION SEQUENCE =======\n");

    for (int i = 1; i <= FLOORS; i++)
    {
        printf("Floor %d: ", i);

        for (int j = 1; j <= SLOTS_PER_FLOOR; j++)
        {
            if (reservedParking[i - 1][j - 1] == 1)
            {
                printf("Slot %d (Reserved)", j);
            }
            else
            {
                printf("Slot %d", j);
            }

            if (j < SLOTS_PER_FLOOR)
            {
                printf(" -> ");
            }
        }

        printf("\n");
    }

    printf("===================================\n");
}
