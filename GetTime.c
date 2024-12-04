//
// Created by lorenzo on 28/11/24.
//

#include "GetTime.h"

struct timespec start, end;

void showElapsedTime(void) {
    double elapsedTime = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    Write("Elapsed Time: ");
    WriteDouble(elapsedTime);
    Write(" s\n");
}

void getTimeStart() {
        clock_gettime(CLOCK_MONOTONIC, &start); // Stores time at start of program
}

void getTimeEnd() {
        clock_gettime(CLOCK_MONOTONIC, &end); // Stores time at start of program
}
