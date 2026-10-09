
#include <stdio.h>
#include "parking.h"
#include "special_parking.h"

int main()
{
    int choice;

    initializeParking();

    while (1)
    {
        printf("\n======= MULTI-STOREY PARKING =======\n");
        printf("1. Park Regular Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Display Reserved Slots\n");
        printf("5. Park Special Vehicle\n");
        printf("6. Vehicle Exit\n");
        printf("7. Exit Application\n");
        printf("====================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
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
                displayReservedSlots();
                break;

            case 5:
                parkSpecialVehicle();
                break;

            case 6:
                exitVehicle();
                break;

            case 7:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
