/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primes.h
 * Author: brandon
 *
 * Created on April 25, 2017, 7:07 PM
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime {
    int prime;
    int power;
    Prime(int);
};
Prime::Prime(int a) {
    prime = a;
    power = 1;
}

class Primes {
private:
    int n; //Number to be factored
    int calc; //Copy of n to run calculations on
    vector<Prime> prime;
public:
    Primes(int); //Meant to be initialized with pre-checked input
    
    void output();
};

Primes::Primes(int input) {
    //Initialize member properties
    n = input;
    calc = input;
    
    //Loop to look for factors (primes will be found first)
    for (int i = 2; i <= n; i++) {
        //If the current integer is a factor
        if (calc % i == 0) {
            //Create a new Prime instance
            Prime x(i);
            //Push the prime instance into the prime vector member
            prime.push_back(x);
            calc /= i;
            
            //Loop again to check if i can be factored out more than once
            while (calc % i == 0) {
                calc /= i;
                prime[prime.size() - 1].power++;
            }
        }
        //If number can no longer be factored, break loop
        if (calc == 1) i = n;
    }
}

void Primes::output() {
    cout << n << " = ";
    for (int i = 0; i < prime.size(); i++) {
        cout << prime[i].prime << '^' << prime[i].power;
        if (i != prime.size() - 1) cout << " * ";
    }
    cout << endl;
}

#endif /* PRIMES_H */

