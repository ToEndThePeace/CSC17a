/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 22, 2017, 1:12 PM
 */

#include <cstdlib>

using namespace std;

/*
 * ENUMERATED DATA TYPES
 * 
 * enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
 * workDay = WEDNESDAY;
 * 
 * workDay = 3; //WRONGGNGNGNGGN
 * workDay = static_cast<Day>(3); /RIGHT
 * 
 * for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Day>(workDay + 1) {};
 * 
 * 
 * FLAGS
 * 
 * flags are like this 
 *          ios::in, ios::out
 *          they stand for something like 000100000 and 010000000
 *          to use flags, bitwise or them
 * dFile.open("file", "ARG", ios::in | ios::out);
 */
int main(int argc, char** argv) {

    return 0;
}

