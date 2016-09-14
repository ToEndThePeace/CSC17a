/* 
 * File:    main.cpp
 * Author:  Brandon Ramirez
 * Created: September 14, 2016, 1:29 PM
 * Purpose: To demonstrate knowledge of pointer notation.
 */

#include <cstdlib>
using namespace std;


int v1 = 25;
int * const p1 = &v1;

int v2 =  22;
const int * const p2 = &v2;

//DYNAMIC ALLOCATION EXAMPLE
/*
 *  const int SIZE = 25;
 *  arrayPtr = new int[SIZE];
 *  for (int i = 0; i < SIZE; i++) {
 *      arrayPtr[i] = i * i;
 *  }
 *  --OR--
 *  for (int i = 0; i < SIZE; i++) {
 *      *(arrayPtr + i) = i * i;
 *  }
 * delete [] arrayPtr;
 * arrayPtr = null;
 */


void swap (int *, int *);
void swap (int &, int &);

int main(int argc, char** argv) {

    
    return 0;
}

void swap (int *a, int *b) {
    //When declaring dereferenced pointers,
    //You have to dereference each instance of variable
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void swap (int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}