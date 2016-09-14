/* 
 * File:    main.cpp
 * Author:  Brandon Ramirez
 * Created: September 14, 2016, 1:56 PM
 * Purpose: 
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


int* fillAry(int);

void output(int*, int);
/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(0));
    
    const int SIZE = 10;
    int *array;
    
    
    array = fillAry(SIZE);
    output(array, SIZE);
    
    delete [] array;
    
    return 0;
}

int* fillAry(int n) {
    //Allocate Memory
    int *a = new int[n];
    for (int i=0;i<n;i++) {
        a[i] = rand() * 90 + 10;
    }
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}