/* 
 * File:    main.cpp
 * Author:  Brandon Ramirez
 * Created: September 12, 2016, 1:43 PM
 * Purpose: Basic pointer notation
 */
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a(25);
    int *ptr = &a;
    cout << a << endl << ptr << endl;
    cout << &a << endl << *ptr << endl;
    cout << *&a << endl << &*ptr << endl;
    
    cout << endl << endl;
    
    int vals[] = {4, 7, 11};
    cout << *vals << endl << vals << endl;
    
    int *valptr = vals;
    cout << valptr[1] << endl << valptr[0];
    return 0;
}

