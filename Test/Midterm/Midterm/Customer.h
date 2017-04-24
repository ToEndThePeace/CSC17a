/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customer.h
 * Author: rcc
 *
 * Created on April 24, 2017, 1:02 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer {
    std::string name, adrs;
    int acNum, bal, curBal;
    std::vector<int> chks, depsts;
    Customer(int);
    void receipt();
};

Customer::Customer(int x) {
    //Input Values
    cout << "Balance Checker" << endl << endl <<
            "Please input your: " << endl <<
            "Name: ";
    cin.ignore(256, '\n');
    getline(cin, name);
    cout << "Address: ";
    getline(cin, adrs);
    cout << "Account Number: ";
    cin >> acNum;
    cout << "Starting Balance: $";
    cin >> bal;
    cout << "Input values for all checks written. Enter $0 to stop." << endl;
    int n;
    do {
        cout << ">> $";
        cin >> n;
        if (n != 0) chks.push_back(n);
    } while (n != 0);
    cout << "Input values for all deposits this month. Enter $0 to stop." << endl;
    do {
        cout << ">> $";
        cin >> n;
        if (n != 0) depsts.push_back(n);
    } while (n != 0);
    
    cout << "Calculating current balance..." << endl;
    
    //Determine Current Balance
    curBal = bal;
    for (int i = 0; i < depsts.size(); i++) {
        curBal += depsts[i];
    }
    for (int i = 0; i < chks.size(); i++) {
        curBal -= chks[i];
    }
    cout << "Your current balance is: $" << curBal << "." << endl;
    
    //Determine Fees
    if (curBal < 0) {
        cout << "Because your account is overdrawn, you owe a $15 fee." << endl;
        curBal -= 15;
        cout << "Your current balance with the fee is: $" << curBal << "." << endl;
    }
    receipt();
}
void Customer::receipt() {
    cout << "Here is your receipt:" << endl <<
            setw(14) << left << name << right << acNum << endl << 
            left << adrs << endl <<
            "Starting Balance: $" << bal << endl <<
            "Current Balance:  $" << curBal << endl <<
            "Checks: ";
    for (int i = 0; i < chks.size(); i++) cout << "$" << chks[i] << " ";
    cout << endl <<
            "Deposits: ";
    for (int i = 0; i < depsts.size(); i++) cout << "$" << depsts[i] << " ";
    cout << endl;
    cin.ignore(256, '\n');
    cin.get();
}

#endif /* CUSTOMER_H */

