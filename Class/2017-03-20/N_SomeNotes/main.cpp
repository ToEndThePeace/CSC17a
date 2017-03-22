/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 20, 2017, 12:55 PM
 */

#include <cstdlib>

using namespace std;

/*
 * Abstract Data Types
 *   abstraction ~ a def that captures general characteristics w/o details
 * 
 * Structures
 *   ~ C++ construct that allows variables to be grouped
 * Example:
struct <structName> {
    type1 field1;
    type2 field2;
    .....
};
 */
struct Student { // Starts with a capital letter
    int studentID; // No data allocated
    string name; // No variables created
    short yearInSchool;
    float GPA;
}; // Ends with a semicolon
/*
 * Example use:
 *   Student stu1;
 *   stu1.name = "Brandon";
 * 
 * Typically, structures are defined in an external file
 * 
 * -> AN ARRAY OF STRUCTURES IS A TABLE!?!?
 * 
 * Structures can be initialized in declarations
 *      Student bill = {12345, "Bill", 3, 4.78};
 * 
 * Pay attention to how you're passing structures into functions!
 * Passing large structures by copy can greatly slow your computer!
 *      -> void showItem(const InventoryItem &p)
 * 
 * POINTERS TO STRUCTURES
 * 
 * cout << (*stuPtr).studID; /> //Parenthesis fix operator precedence
 * SAME AS
 * cout << stuPtr->studentID;  
 * 
 * 
 * Don't declare more than one structure per header file~
 * 
 */


int main(int argc, char** argv) {

    return 0;
}

/*
 * Do dynamic arrays but in all pointer notation or something?
 */