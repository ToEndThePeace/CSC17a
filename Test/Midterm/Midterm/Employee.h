/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: rcc
 *
 * Created on April 24, 2017, 1:29 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    string name;
    float hrs, payRt, gross;
    
    bool setInfo();
    void paycheck();
};

bool Employee::setInfo() {
    //Input Values
    cout << "Please Input Your: " << endl <<
            setw(15) << "Name: ";
    cin.ignore(256, '\n');
    getline(cin, name);
    cout << setw(15) << "Payrate: ";
    cin >> payRt;
    if (payRt < 0) return false;
    cout << setw(15) << "Hours Worked: ";
    cin >> hrs;
    if (hrs < 0) return false;
    
    //Nested ternary operators to determine gross pay based on hours worked
    gross = hrs <= 40 ? hrs * payRt :
            hrs <= 50 ? 40 * payRt + (hrs - 40) * payRt * 2 :
                        40 * payRt + 10 * payRt * 2 + (hrs - 50) * payRt * 3;
    
    return true;
}

void Employee::paycheck() {
    cout << "************************" << endl <<
            "*    Bio Industries    *" << endl <<
            "*   123 Infinity Way   *" << endl <<
            "*   -   Paycheck   -   *" << endl <<
            "************************" << endl <<
            "Name:      " << name << endl <<
            "Amount:    $" << gross << endl <<
            "Signature: _____________" << endl;
}

#endif /* EMPLOYEE_H */

