
#include <stdio.h>
#include "parking.h"
#include "history.h"
#include "analysis.h"
#include "special_parking.h"
#include "priority.h"

int main(void)
{
    int choice;

    initializeParking();
    initializeHistory();

    while (1)
    {
        printf("\n====== MULTI-STOREY PARKING MANAGEMENT ======\n");
        printf("1. Park Regular Vehicle\n");
        printf("2. Search Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Display Active Vehicles\n");
        printf("5. Display Parking History\n");
        printf("6. Vehicle Exit\n");
        printf("7. Occupancy Analysis\n");
        printf("8. Guide to Available Slot\n");
        printf("9. Display Reserved Slots\n");
        printf("10. Park Special Vehicle\n");
        printf("11. Display Available Slots\n");
        printf("12. Display Allocation Sequence\n");
        printf("13. Exit Application\n");
        printf("=============================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
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
                displayReservedSlots();
                break;
            case 10:
                parkSpecialVehicle();
                break;
            case 11:
                displayAvailableSlots();
                break;
            case 12:
                displayAllocationSequence();
                break;
            case 13:
                printf("\nThank you for using the system!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}
