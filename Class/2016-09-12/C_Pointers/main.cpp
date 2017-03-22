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
    cout << valptr[1] << endl << valptr[0] << endl;
    cout << *(vals + 2) << endl;
    cout << *(valptr + 2) << endl << *(valptr + 1) << endl;
    
    int x, *xpt(&x);
    cout << x << endl << xpt << endl << *xpt << endl;
    return 0;
}

