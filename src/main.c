
#include <stdio.h>
#include "parking.h"
#include "priority.h"

int main()
{
    int choice;

    initializeParking();

    while (1)
    {
        printf("\n========== MULTI-STOREY PARKING ==========\n");
        printf("1. Park Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Display Available Slots\n");
        printf("5. Display Allocation Sequence\n");
        printf("6. Check Full Parking\n");
        printf("7. Exit\n");
        printf("==========================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                parkVehicle();
                break;

            case 2:
                searchVehicle();
                break;

            case 3:
                displayParkingStatus();
                break;

            case 4:
                displayAvailableSlots();
                break;

            case 5:
                displayAllocationSequence();
                break;

            case 6:
                if (isParkingFull())
                    printf("\nParking area is FULL!\n");
                else
                    printf("\nParking spaces are available.\n");
                break;

            case 7:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
