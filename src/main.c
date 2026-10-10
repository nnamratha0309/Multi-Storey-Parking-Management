#include <stdio.h>
#include "parking.h"
#include "history.h"
#include "analysis.h"

int main(void)
{
    int choice;

    initializeParking();
    initializeHistory();

    while (1)
    {
        printf("\n====== MULTI-STOREY PARKING MANAGEMENT ======\n");
        printf("1. Park Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Display Active Vehicles (S7)\n");
        printf("5. Display Parking History (S7)\n");
        printf("6. Vehicle Exit (S7)\n");
        printf("7. Occupancy Analysis (S8)\n");
        printf("8. Guide to Available Slot (S8)\n");
        printf("9. Exit Application\n");
        printf("=============================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            while (getchar() != '\n')
                ;

            continue;
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
                displayActiveVehicles();
                break;

            case 5:
                displayParkingHistory();
                break;

            case 6:
                exitVehicle();
                break;

            case 7:
                displayOccupancyAnalysis();
                break;

            case 8:
                guideToAvailableSlot();
                break;

            case 9:
                printf("\nThank you for using the system!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
