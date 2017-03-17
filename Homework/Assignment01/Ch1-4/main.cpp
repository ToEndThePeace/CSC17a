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
 * Chapters 1-4    *
 *******************/

int main(int argc, char** argv) {

    /*
     * Problem 3.12 
     */
    char letter;
    
    cout << "Please enter a character to convert to ASCII: ";
    cin >> letter;
    cout << endl << "The ASCII code of your character is: " << int(letter) <<
            endl << endl;
    
    /*
     * Problem 3.13
     * 
     * The following will be output:
     * > 9
     * > 9.5
     * > 9
     */
    
    /*
     * Problem 4.10
     */
    int sales, bonus(0);
    float commissionRate;
    if (sales > 50000) {
        commissionRate = 0.25;
        bonus += 250;
    }
    
    /*
     * Problem 4.14
     * Same variables as Problem 4.10 but with an Else statement
     */
    if (sales >= 50000) commissionRate = 0.1;
    else                commissionRate = 0.2;
    
    /*
     * Problem 4.24
     * "Rewrite the following if/else statements as conditional expressions"
     * 
     * > z = x > y ? 1 : 20;
     * > population = base * (temp > 45 ? 10 : 2);
     * > wages *= hours > 40 ? 1.5 : 1;
     * > cout << "The result is " << result >= 0 ? "posi" : "nega" << "tive.\n";
     */
    
    return 0;
}

