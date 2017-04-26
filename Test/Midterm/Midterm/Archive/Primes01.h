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
    unsigned char prime;
    unsigned char power;
    
    Prime();
    Prime(int n) : prime(n), power(1) {}
};

struct Primes {
    int n; //Number to be factored
    Prime *prime;
    unsigned char nPrimes;
    
    Primes() : nPrimes(0) {}
    void addPrime(int &, int);
    void output();
};

Primes *factor(int n) { //Where n was already boundary-checked
    Primes *p = new Primes; //New pointer to a Prime struct
    int newN = n; //Copy of number to perform calculations on
    
    for (int i = 2; i < n; i++) {
        //If the number is a 
        if (newN % i == 0) p->addPrime(newN, i);
        if (newN == 1) i = n;
    }
    return p;
}
/**
 * 
 * @param newN a reference to the number holding number being factored
 * @param fact the next prime factor to add to the array
 */
void Primes::addPrime(int &newN, int fact) {
    //Create a new temp array of primes
    Prime *temp = new Prime[nPrimes + 1];
    for (int i = 0; i < nPrimes; i++) {
        temp[i] = prime[i];
    }
    
    //Add new prime to array
    nPrimes++;
    Prime x(fact);
    temp[nPrimes] = x;
    
    //It also factors out the prime
    newN /= fact;
    
    //If the prime can be factored out any more times, 
    //This loops factors them out and increments the power in the Prime object
    while (newN % fact == 0) {
        newN /= fact;
        prime[nPrimes].power++;
    }
    
    //Delete old array and replace it with new temp array
    delete[] prime;
    prime = temp;
}
void Primes::output() {
    cout << n << " = ";
    for (int i = 0; i < nPrimes; i++) {
        cout << prime[i].prime << '^' << prime[i].power;
        if (i != nPrimes - 1) cout << " * ";
    }
    cout << endl;
}

#endif /* PRIMES_H */

