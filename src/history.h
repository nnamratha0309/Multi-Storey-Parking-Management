#ifndef HISTORY_H
#define HISTORY_H

#include "parking.h"

#define MAX_HISTORY 100

extern Vehicle parkingHistory[MAX_HISTORY];
extern int historyCount;

void initializeHistory(void);
void displayActiveVehicles(void);
void displayParkingHistory(void);
void exitVehicle(void);

#endif
