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
#include <time.h>
#include <ctime>
#include <vector>
#include <float.h>
using namespace std;

#include "Customer.h"
#include "Employee.h"
#include "statsResult.h"
#include "Encrypt.h"

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
                cout << "Goodbye forever I guess" << endl;
                break;
            default:
                cout << "Invalid selection.";
        }
        cin.ignore(256, '\n');
        cin.get();
    } while (inp < 8);
    
    
    return 0;
}

void p1() {
    Customer c1(0);
}
void p2() {
    cout << "Paycheck Calculator" << endl;
    
    bool v(true);
    vector<Employee> emps;
    do {
        cout << "New Employee:" << endl;
        Employee e;
        v = e.setInfo();
        if (v == true) emps.push_back(e);
    } while (v == true);
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
    cin >> n;
    
    int *ary = new int[n];
    
    cout << "Please enter " << n << " numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "> ";
        cin >> ary[i];
    }
    
    //Sort the array to perform statistical analysis on it
    sort(ary, n);
    
    //Perform the analysis and return a structure of results
    statsResult *res = avgMedMode(ary, n);
    
    delete[] ary;
    delete[] res;
}
void p4() {
    cout << "Encryption Algorithm" << endl;
    
    string s;
    int input;
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
void p6() {}
void p7() {}

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
string getS() {
    string s;
    cout << ">> ";
    cin >> s;
    return s;
}