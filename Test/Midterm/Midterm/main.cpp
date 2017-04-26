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
#include <iomanip>
#include <vector>
using namespace std;

#include "Customer.h"
#include "Employee.h"
#include "statsResult.h"
#include "Encrypt.h"
#include "Primes.h"

void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();

void sort(int *, int);
void swap(int &, int &);

int Menu();
int getN();
string getS();

int main(int argc, char** argv) {

    int inp(0);
    
    do {
        inp = Menu();
        cout << endl;
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid selection.";
        }
        if (inp != 8) {
            cin.ignore(256, '\n');
            cin.get();
        }
    } while (inp != 8);
    
    
    return 0;
}

void p1() {
    //Declare instance of the customer class, everything is done in that
    Customer c1(0);
}
void p2() {
    cout << "Paycheck Calculator" << endl;
    
    bool v(true);
    vector<Employee> emps;
    //Create a new employee as long as input is valid
    do {
        cout << "New Employee:" << endl;
        Employee e;
        v = e.setInfo();
        if (v == true) emps.push_back(e);
    } while (v == true);
    //Once invalid data is entered, display all employee paychecks
    cout << "Invalid input." << endl <<
            "Here are all employee paychecks." << endl;
    for (int i = 0; i < emps.size(); i++) {
        emps[i].paycheck();
        cin.ignore(256, '\n');
        cin.get();
    }
}
void p3() {
    int n;
    cout << "Stat Calculator" << endl << 
            "How many values are in your list? ";
    cin >> n; //Number of values user wishes to input
    
    //Creates array of n values
    int *ary = new int[n];
    
    //Inputs n values into array
    cout << "Please enter " << n << " numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "> ";
        cin >> ary[i];
    }
    
    //Sort the array to perform statistical analysis on it
    sort(ary, n);
    
    //Perform the analysis and return a structure of results
    statsResult *res = avgMedMode(ary, n);
    
    //Clean up
    delete[] ary;
    delete[] res;
}
void p4() {
    cout << "Encryption Algorithm" << endl;
    
    string s;
    int input;
    //Encryption is run on reference to s (original string is encrypted)
    do {
        cout << "Enter a number to encrypt." << endl <<
                "(Encryption will loop until invalid number is entered.)" << endl;
        cin >> s;
        if (canEncrypt(s)) {
            encrypt(s);
            cout << "Encrypted: " << s << endl;
        } else {
            cout << "Invalid entry." << endl;
        }
        cin.ignore(256, '\n');
        cin.get();
    } while (canEncrypt(s));
}
void p5() {
    cout << "Largest Factorials Possible for Data Types:" << endl <<
            "Signed Char:    5!" << endl <<
            "Unsigned Char:  5!" << endl <<
            "Signed Short:   7!" << endl <<
            "Unsigned Short: 8!" << endl <<
            "Signed Int:     12!" << endl <<
            "Unsigned Int:   12!" << endl <<
            "Signed Long:    20!" << endl <<
            "Unsigned Long:  20!" << endl <<
            "Float:          12!" << endl <<
            "Double:         20!" << endl;
}
void p6() {
    cout << "Number Conversions" << endl << 
            endl <<
            "Decimal Given: 2.325" << endl <<
            "       Binary: 10.010(1001)" << endl <<
            "        Octal: 2.2(4631)" << endl <<
            "  Hex Literal: 2.5(3)" << endl <<
            "    Hex Float: 0x4014CCCC" << endl <<
            endl <<
            "Decimal Given: -2.325" << endl <<
            "       Binary: -10.010(1001)" << endl <<
            "        Octal: -2.2(4631)" << endl <<
            "  Hex Literal: -2.5(3)" << endl <<
            "    Hex Float:  0xC014CCCC" << endl <<
            endl <<
            "Decimal Given: 0.1453125" << endl <<
            "       Binary: 0.0010010(1001)" << endl <<
            "        Octal: 0.112(3157)" << endl <<
            "  Hex Literal: 0.25(3)" << endl <<
            "    Hex Float: 0x3E14CCC" << endl <<
            endl <<
            "Decimal Given: -0.1453125" << endl <<
            "       Binary: -0.0010010(1001)" << endl <<
            "        Octal: -0.112(3157)" << endl <<
            "  Hex Literal: -0.25(3)" << endl <<
            "    Hex Float:  0xBE14CCC" << endl <<
            endl <<
            "Hex Float Given: 0x59999901" << endl <<
            "  Decimal Float: 5.4042376e15" << endl <<
            endl <<
            "Hex Float Given: 0x59999902" << endl <<
            "  Decimal Float: 5.4042382e15" << endl <<
            endl <<
            "Hex Float Given:  0xA66667FE" << endl <<
            "  Decimal Float: -7.9938215e-16" << endl;
}
void p7() {
    cout << "Factoring to Primes" << endl << endl;
    int min(2), max(10000); //Bounds for the user input
    
    int n(0); //Number input to factor
    do { //This loop takes user input until a valid number is entered
        if (n != 0) cout << "Please pick a number between 2 and 10,000." << endl;
        cout << "Enter a number to factor: ";
        cin >> n;
    } while (n < min || n > max);
    
    //Factor the integer input by user and output factor list
    Primes obj(n);
    obj.output();
}

void sort(int *ary, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ary[j] < ary[i]) swap(ary[i], ary[j]);
        }
    }
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Menu() {
    cout << "Choose a problem:" << endl <<
            "1: Balance Calculator" << endl <<
            "2: Paycheck Calculator" << endl <<
            "3: Statistical Analysis" << endl <<
            "4: Encryption" << endl <<
            "5: Factorial Limits" << endl <<
            "6: Number Conversions" << endl <<
            "7: Factoring" << endl <<
            "8: Exit" << endl;
    return getN();
}
int getN() {
    int n;
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