/* 
 * Name: Brandon Ramirez
 * 
 */

#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

/*
 * Kerningham C Book <--- buy it>
 * 
 */

int *fillAry(int);
int *fillAry(int, int);

void prntAry(int *, int, int);

void markSort(int *, int);

int main(int argc, char** argv) {
    
     //Change these numbers to adjust # of modes
    int size   = 39;
    int factor   = 7;
    int *array = fillAry(size, factor);
    
    //Print the Array
    prntAry(array, size, factor);
    
    //Sort Array
    markSort(array, size);
    
    //Print Sorted Array
    prntAry(array, size, size / factor);
    
    //Delete array
    delete []array;
    
    return 0;
}

int *fillAry(int n) {
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    return a;
}
int *fillAry(int n, int mod) {
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i % mod;
    }
    return a;
}
void prntAry(int *a, int n, int perLine) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (a[i] < 10 ? "  " : " ") << a[i];
        if (i % perLine == (perLine - 1)) cout << endl;
    }
    cout << endl;
}
void markSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}