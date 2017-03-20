/* 
 * File:    main.cpp
 * Author:  Brandon Ramirez
 * Created: Mar 17, 2017 2:16:52 PM
 * Class:   CSC17A
 * Purpose: To review the creation, declaration, and destruction of pointers
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *mmm(int *, int);


//Basic Array Functions (Helpers)
int *fillAry(int);
void output(int *, int);
void swap(int, int);
void sort(int *);

//Executable Code
int main(int argc, char** argv) {
    //Menu
    srand(time(0));
    
    /*cout << "Which problem should I open?" << endl <<
            "1. Mean, Median, and Mode" << endl <<
            "2. "
            ""
            ">> ";*/

    int s1 = 20;
    int *a1 = fillAry(s1);
    output(a1, s1);
    
    delete[] a1;
    //Return
    return 0;
}

//Function Declarations
int *mmm(int *a, int n) {
    
}

int *fillAry(int n) {
    int *a = new int(0);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 90 + 10;
    }
    return a;
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}