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
    Prime(int a) {
        prime = a;
        power = 1;
    }
};

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
    n = input;
    calc = input;
    
    for (int i = 2; i < n; i++) {
        //If the number is a prime factor
        if (calc % i == 0) {
            //Create new Prime object and add it to array
            Prime x(i);
            prime.push_back(x);
            
            //Factor the prime number out of calc
            calc /= i;
            
            //If the prime can still be factored out,
            //continue to factor and increment power
            while (calc % i == 0) {
                calc /= i;
                prime[prime.size()].power++;
            }
        }
        //Break the loop if there are no more factors
        if (calc == 1) i = n;
    }
}

void Primes::output() {
    cout << n << " = ";
    for (int i = 0; i < prime.size(); i++) {
        cout << prime[i].prime << '^' << prime[i].power;
        if (i != prime.size()) cout << " * ";
    }
    cout << endl;
}

#endif /* PRIMES_H */

