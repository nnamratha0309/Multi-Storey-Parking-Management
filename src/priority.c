#include <stdio.h>
#include "priority.h"

int getAvailableSlots(int floor)
{
    int count = 0;

    for (int j = 0; j < SLOTS_PER_FLOOR; j++)
    {
        if (parking[floor - 1][j] == 0)
        {
            count++;
        }
    }

    return count;
}

int isFloorFull(int floor)
{
    if (getAvailableSlots(floor) == 0)
    {
        return 1;
    }

    return 0;
}

int isParkingFull()
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

int findPriorityFloor()
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
    for (int j = 0; j < SLOTS_PER_FLOOR; j++)
    {
        if (parking[floor - 1][j] == 0)
        {
            return j + 1;
        }
    }

    return -1;
}

void displayAvailableSlots()
{
    printf("\n========== AVAILABLE SLOTS ==========\n");

    for (int i = 1; i <= FLOORS; i++)
    {
        printf("Floor %d : %d slot(s) available\n",
               i, getAvailableSlots(i));
    }

    printf("=====================================\n");
}

void displayAllocationSequence()
{
    printf("\n======= ALLOCATION SEQUENCE =======\n");

    for (int i = 1; i <= FLOORS; i++)
    {
        printf("Floor %d: ", i);

        for (int j = 1; j <= SLOTS_PER_FLOOR; j++)
        {
            printf("Slot %d", j);

            if (j < SLOTS_PER_FLOOR)
            {
                printf(" -> ");
            }
        }

        printf("\n");
    }

    printf("===================================\n");
}