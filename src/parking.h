#ifndef PARKING_H
#define PARKING_H

#define FLOORS 3
#define SLOTS_PER_FLOOR 5
#define MAX_VEHICLES 15

typedef struct
{
    char registrationNumber[20];
    int floor;
    int slot;
} Vehicle;

extern int parking[FLOORS][SLOTS_PER_FLOOR];
extern Vehicle vehicles[MAX_VEHICLES];
extern int vehicleCount;

void initializeParking();
void parkVehicle();
void searchVehicle();
void displayParkingStatus();

#endif