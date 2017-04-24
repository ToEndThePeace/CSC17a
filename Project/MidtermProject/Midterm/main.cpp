/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: brandon
 *
 * Created on April 24, 2017, 12:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();


void Menu();
int getN();
float getN();
string getS();

int main(int argc, char** argv) {

    int inp(0);
    
    do {
        inp = Menu();
        switch (inp) {
            case 1:
                p1();
                break;
            case 2:
                p2();
                break;
            case 3:
                p3();
                break;
            case 4:
                p4();
                break;
            case 5:
                p5();
                break;
            case 6:
                p6();
                break;
            case 7:
                p7();
                break;
            case 8:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid selection.";
        }
        
    } while (inp < 8);
    
    
    return 0;
}

void p1() {
    struct Customer {
        string name, adrs;
        int acNum;
        float bal;
        vector<float> chks;
        vector<float> depsts;
    };
    Customer c1;
    cout << "Balance Checker" << endl << endl <<
            "Please input your: " << endl <<
            "Name";
    c1.name = getS();
}

void Menu() {
    cout << "Choose a problem:" << endl <<
            "1: Problem 1" << endl <<
            "2: Problem 2" << endl <<
            "3: Problem 3" << endl <<
            "4: Problem 4" << endl <<
            "5: Problem 5" << endl <<
            "6: Problem 6" << endl <<
            "7: Problem 7" << endl <<
            "8: Exit" << endl;
    return getN();
}
int getN() {
    int n;
    cout << ">> ";
    cin >> n;
    return n;
}
float getN() {
    float n;
    cout << ">> ";
    cin >> n;
    return n;
}
string getS() {
    string s;
    cout << ">> ";
    cin >> s;
    return s;
}