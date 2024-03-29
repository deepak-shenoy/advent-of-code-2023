/*
 * Advent of Code
 * Deepak Shenoy
 *
 * Day 01 - Part 2
 * February 7th, 2024
 *
 */

#include <iostream>

void raceTimes(int totalSeconds) {

    printf("===============================================\n");
    for(int i = 0; i < totalSeconds; i++) {
        printf("Run %i: speed=%i, run-time=%i, distance=%i\n",
               i, i, (totalSeconds - i), (totalSeconds - i) * i);
    }
    printf("===============================================\n\n");
}

int main() {
    // Time allowed for each race
    // Best distance recorded for each race
    // To win - you need to go father in each race than the current holder
    // Time of holding down button charges the boat - the longer you hold the faster the speed - but time is subtracted
    // Releasing button allows the boat to move forward

    // 7 Seconds total = total_seconds
    // ------------------------
    // hold 1s Speed of 1 mm/s for time of  6ms distance of   6 mm
    // hold 2s Speed of 2 mm/s for time of  5ms distance of  10 mm
    // hold 3s Speed _________ for time of  4ms distance of  12 mm
    // hold 4s Speed _________ for time of  3ms distance of  12 mm
    // hold 5s Speed _________ for time of  ___ distance of  10 mm
    // hold 6s Speed _________ for time of  ___ distance of   6 mm
    // hold 7s Speed of 0 ms/s for time of  0ms distance of   0 mm
    // Formula = (total_seconds - hold_time) * hold_time

    raceTimes(7);



    // Third race
    // total_seconds = 19
    // Max hold times between 11 - 18 (9 inclusive combinations)

    raceTimes(30);

    return 0;
}
