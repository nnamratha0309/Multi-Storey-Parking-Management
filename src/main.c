#include <stdio.h>
#include "parking.h"

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
        printf("4. Exit\n");
        printf("==========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}