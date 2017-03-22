/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 6, 2017, 1:27 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *ptr;
    int x;
    ptr = &x;
    *ptr = *&x;
    
    int vals[] = {4, 7, 3};
    cout << vals    << endl << //Outputs address
            vals[0] << endl << //Outputs 4
            *vals   << endl;   //Outputs 4
    
    const int SIZE = 6;
    const float payRate[SIZE] = {22.25, 18.75, 18.25, 12.2, 13.0, 15.50};
    
    int value = 22;
    //           this signifies that the pointer is constant
    //       ____|____
    //       |       |
    const int * const ptr2 = &value;
    
    return 0;
}

