/*
 * Name    : Brandon Ramirez
 * Date    : 3 March 2017
 * Purpose : To practice creating, utilizing, and cleaning 2D static arrays
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Static Array Columns are a GLOBAL CONSTANT
const int COLS = 5;

//Function Prototypes
void fillAry(int [][COLS], int);
void prntAry(int [][COLS], int);
void prntAds(int [][COLS], int);

int main(int argc, char** argv) { //Could also be char *argv[]
    
    //Generate Random Seed
    srand(time(0));
    
    //Declare and Set Array Parameters
    const int ROWS = 10;
    
    //Create Array
    int table[ROWS][COLS] = {};
    
    //Check Array Initialization
    prntAry(table, ROWS);
    
    //Fill Array
    fillAry(table, ROWS);
    
    //Print Array and Addresses
    prntAry(table, ROWS);
    prntAds(table, ROWS);
    
    //Exit
    return 0;
}

//Returns a 2D Dynamic Array
void fillAry(int a[][COLS], int row){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COLS; j++) {
            a[i][j] = rand() % 90 + 10;
        }
    }
}

void prntAry(int a[][COLS], int ROWS) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void prntAds(int a[][COLS], int ROWS) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << &a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}