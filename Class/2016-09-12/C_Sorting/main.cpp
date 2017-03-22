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
void fillArray(int [], int);
void printArray(int [], int, int);

void markSort(int [], int);

//Program Execution
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    
    int perLine=10;
    const int SIZE=100;
    int array[SIZE];
    
    //Input Data
    fillArray(array,SIZE);
    
    //Display Initialization
    printArray(array,SIZE,perLine);
    
    //Process->Map input data to output
    markSort(array,SIZE);
    
    //Display/Output Solution
    printArray(array,SIZE,perLine);
    
    //Exit
    return 0;
}

//Function Declarations
void markSort(int a[],int n) {
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}
void fillArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand()%90 + 10; // Random 2-digit int
    }
}
void printArray(int a[], int n, int perLine) {
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}