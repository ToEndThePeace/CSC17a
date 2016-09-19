/* 
 * File:    main.cpp
 * Author:  Brandon Ramirez
 * Created: September 19, 2016, 1:00 PM
 * Purpose: To create functional programs utilizing 2d arrays
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * HOMEWORK PROBLEM:
 * Mean, Median, and Mode of a data set
 * encapsulated into a nice menu-based program
 */


int* fill(int);//Overload it
int** fill(int, int);

void output(int*, int, int);
void output(int**, int, int);

int main(int argc, char** argv) {
    srand(time(0));
    
    const int ROW = 10;
    const int COL = 10;
    int perL = COL;
    const int SIZE = ROW * COL;
    
    int *l;
    int **a;
    
    l = fill(SIZE);
    a = fill(ROW, COL);
    
    output(l, SIZE, perL);
    output(a, ROW, COL);
    
    //Output specific row, col
    int srow = 4;
    int scol = 7;
    
    cout << "Row " << srow + 1 << endl;
    for (int i = 0; i < COL; i++) {
        cout << l[srow * 10 + i] << " ";
    }
    cout << endl;
    cout << "Col " << scol + 1 << endl;
    for (int i = 0; i < ROW; i++) {
        cout << l[scol + 10 * i] << " ";
    }
    cout << endl << endl;
    
    cout << "Row " << srow + 1 << endl;
    for (int i = 0; i < COL; i++) {
        cout << a[srow][i] << " ";
    }
    cout << endl;
    cout << "Column " << scol + 1 << endl;
    for (int i = 0; i < ROW; i++) {
        cout << a[i][scol] << " ";
    }
    cout << endl;
    
    
    for (int i = 0; i < ROW; i++) {
        delete [] a[i];
    }
    delete [] a;
    a = NULL;
    delete [] l;
    l = NULL;
    
    return 0;
}

int* fill(int x) {
    int *a = new int[x];
    for (int i = 0; i < x; i++) {
        a[i] = rand() % 90 + 10;
    }
    return a;
}
int** fill(int x, int y) {
    int **a = new int*[x];
    for (int i = 0; i < x; i++) {
        a[i] = new int[y];
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            a[i][j] = rand() % 90 + 10;
        }
    }
    return a;
}
void output(int *a, int n, int perline) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        if ((i + 1) % perline == 0) cout << endl;
    }
    cout << endl;
}
void output(int **a, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}