#ifndef PRIORITY_H
#define PRIORITY_H

#include "parking.h"

int getAvailableSlots(int floor);
int isFloorFull(int floor);
int isParkingFull();

int findPriorityFloor();
int findPrioritySlot(int floor);

void displayAvailableSlots();
void displayAllocationSequence();

#endif