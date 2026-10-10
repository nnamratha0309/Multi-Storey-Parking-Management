
#ifndef SPECIAL_PARKING_H
#define SPECIAL_PARKING_H

#include "parking.h"

#define RESERVED_SLOTS 2

extern int reservedParking[FLOORS][SLOTS_PER_FLOOR];

void initializeReservedSlots(void);
void displayReservedSlots(void);
void parkSpecialVehicle(void);
void exitVehicle(void);

#endif
