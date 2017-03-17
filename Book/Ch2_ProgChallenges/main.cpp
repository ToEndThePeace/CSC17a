/* 
 * Name: Brandon Ramirez
 * Date: February 27, 2017
 * CSC17A - Object-Oriented Programming (C++)
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**************************
 *       Chapter 2        *
 * Programming Challenges *
 **************************/

// 1. Sum of Two Numbers
int sum(int, int);

// 2. Product of Two Numbers
int prod(int, int);

// 3. Sales Tax
float totalTax(int, int, float);


int main(int argc, char** argv) {
    
    
    
    return 0;
}

/**
 * Takes two integers as arguments and returns the sum.
 */
int sum(int a, int b) {
    return a + b;
}
/**
 * Takes two integers as arguments and returns the product. 
 */
int prod(int a, int b) {
    return a * b;
}
/**
 * 
 * @param cTax county tax percentage, given as an integer (cTax%)
 * @param sTax state tax percentage, given as an integer (sTax%)
 * @param price total before tax
 * @return the total sales tax
 */
float totalTax(int cTax, int sTax, float price) {
    return price * (cTax + sTax) / 100;
}