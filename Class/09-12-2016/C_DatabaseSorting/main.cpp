/* 
 * File:   main.cpp
 * Author: Brandon Ramirez
 * Created on September 12, 2016, 1:01 PM
 * Purpose: Short sorting algorithm
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillArray(int [], int [], int);
void printArray(int [], int, int);
void printArray(int [], int [], int, int);

void markSort(int [], int[], int);

//Program Execution
int main(int argc, char** argv) {
    
    /*
     * HERES HOW THIS WHOLE THING IS SUPPOSED TO WORK
     * 
     * You keep the original array unchanged, and instead
     * create an array of indices that are sorted based on
     * the original locations of values.
     * 
     * Example:
     * 
     * ORIGINAL: 24  5 12 34  1 51
     * SORTED:    1  5 12 24 34 51
     * INDEX:     4  1  2  0  3  5
     * 
     * The first value in the sorted array is at original[4]
     * Second value is at original[1] etc...
     */
    
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    
    int perLine=10;
    const int SIZE=100;
    int array[SIZE],index[SIZE];
    
    //Input Data
    fillArray(array,index,SIZE);
    
    //Display Initialization
    printArray(array,index,SIZE,perLine);
    
    //Process->Map input data to output
    markSort(array,index,SIZE);
    
    //Display/Output Solution
    printArray(array,index,SIZE,perLine);
    
    //Exit
    return 0;
}

//Function Declarations
void markSort(int a[], int indx[], int n) {
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(indx[i]>indx[j]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}
void fillArray(int a[], int indx[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand()%90 + 10; // Random 2-digit int
        indx[i] = i;
    }
}
void printArray(int a[], int indx[], int n, int perLine) {
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}