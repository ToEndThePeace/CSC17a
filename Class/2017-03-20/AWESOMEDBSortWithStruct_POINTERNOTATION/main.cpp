/*
 * Student: Brandon Ramirez
 * Created: March 22, 2017, 12:30 PM
 * Project: Convert all array indices to pointer indices. 
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Array.h"


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Array *fillAry(int, int);
void prntAry(Array *, int);
void markSrt(Array *);
void destroy(Array *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=100;
    Array *a1 = fillAry(size, 10);
    
    //Output the created array
    prntAry(a1, 10);
    
    //Sort the array
    markSrt(a1);
    
    //Printout the sorted array
    prntAry(a1, 10);

    //Delete the array
    destroy(a1);
    
    //Exit
    return 0;
}

Array *fillAry(int n, int mod) {
    Array *a = new Array;         //Declare Array
    a->size = n > 1 ? n : 2;      //Read in n from args
    a->data = new int[a->size];   //Initialize Arrays and set size
    a->index = new int[a->size];
    //Fill with data
    for (int i = 0; i < a->size; i++) {
        *(a->data + i)  = i % mod;
        *(a->index + i) = i;
    }
    //Return the array
    return a;
}
void prntAry(Array *a, int perLine) {
    for (int i = 0; i < a->size; i++) {
        cout << *(a->data + *(a->index + i)) << " ";
        if (i % perLine == perLine - 1) cout << endl;
    }
    cout << endl;
}

void markSrt(Array *a){ //Sorts the inDEX
    for (int i = 0; i < a->size; i++) {
        for (int j = i + 1; j < a->size; j++) {
            if (*(a->data + *(a->index + i)) > *(a->data + *(a->index + j))) {
                int temp = *(a->index + i);
                *(a->index + i) = *(a->index + j);
                *(a->index + j) = temp;
            }
        }
    }
}

void destroy(Array *a) {
    delete []a->data;
    delete []a->index;
    delete a;
}