/* 
 * Name: Brandon Ramirez
 * Date: February 27, 2017
 * CSC17A - Object-Oriented Programming (C++)
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*******************
 * Review Problems *
 * Chapters 5-8    *
 *******************/

// Prototype for Problem 6.7
void timesTen(int);
// Prototype for Problem 7.25
void displayArray7(const int [][7], int);

int main(int argc, char** argv) {
    /*
     * Problem 5.11
     */
    for (int i = 0; i <= 100; i+= 5) {
        cout << i;
        if (i == 100) cout << "..." << endl;
        else cout << ", ";
    }
    cout << endl;
    
    /*
     * Problem 6.7
     * Prototype located above main(), function located under.
     */
    timesTen(6);
    timesTen(145);
    
    /*
     * Problem 7.6
     * 
     * The following will be output:
     * > 1
     * > 2
     * > 3
     * > 4
     * > 5
     */
    
    /*
     * Problem 8.7
     * There is no Problem 8.7, so I chose two others instead of just one.
     */
    
    /*
     * Problem 7.25
     * "Create a function to output a 2D array with 7 columns."
     * Prototype located above main(), function below.
     */
    
    /*
     * Problem 7.26
     * "Define a 3D array representing 50 racks of 10 shelves 
     *  that each hold 25 DVDs."
     */
    int SETS(50), ROWS(10), COLS(25);
    string dvds[SETS][ROWS][COLS]; // Where array elements are DVD titles.
    
    return 0;
}

// Function for Problem 6.7
void timesTen(int n) {
    cout << n << " x 10 = " << n * 10 << endl;
}
// Function for Problem 7.25
void displayArray7(const int arr[][7], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 7; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}