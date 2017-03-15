/*
 * Name    : Brandon Ramirez
 * Date    : 3 March 2017
 * Purpose : To practice creating, utilizing, and cleaning 2D dynamic arrays
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
int **fillAry(int, int);
void prntAry(int **, int, int);
void prntAdrs(int **, int, int);
void destroy(int **, int);

int main(int argc, char** argv) { //Could also be char *argv[]
    
    //Generate Random Seed
    srand(time(0));
    
    //Declare and Set Array Parameters
    int r1(10), c1(5), r2(20), c2(10);
    
    //Create & Fill Arrays
    int **a1 = fillAry(r1, c1);
    int **a2 = fillAry(r2, c2);
    
    //Print Arrays
    prntAry(a1, r1, c1);
    prntAry(a2, r2, c2);
    
    //Print Array Addresses
    prntAdrs(a1, r1, c1);
    prntAdrs(a2, r2, c2);
    
    //Clean Arrays
    destroy(a1, r1);
    destroy(a2, r2);
    
    //Exit
    return 0;
}

//Returns a 2D Dynamic Array
int **fillAry(int row, int col){
    int **a = new int*[row];
    for (int i = 0; i < row; i++) {
        a[i] = new int[col];
    }
    //Fill with 2 digit nums
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            a[x][y] = rand() % 90 + 10;
        }
    }
    return a;
}

void prntAry(int **a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void prntAdrs(int **a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << &a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void destroy(int **a, int row) {
    for (int i = 0; i < row; i++) {
        delete []a[i];
        a[i] == nullptr;
    }
    delete []a;
    a = nullptr;
}