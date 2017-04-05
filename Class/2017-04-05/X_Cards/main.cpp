/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 5, 2017, 1:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "Card.h"
/*
 * 
 */

int main(int argc, char** argv) {
    srand(time(0));
    
    Card **card = new Card*[52];
    int *index = new int[52];
    for (int i = 0; i < 52; i++) {
        card[i] = new Card(i);
        index[i] = i;
    }
    
    //Shuffle
    for (int shuf = 1; shuf <= 7; shuf++) {
        for (int i = 0; i < 52; i++) {
            int rnd = rand() % 52;
            int temp = index[i];
            index[i] = index[rnd];
            index[rnd] = temp;            
        }
    }
    
    for (int i = 0; i < 52; i++) {
        cout << setw(2) << i << " " <<
                setw(2) << card[index[i]]->getFVal() << card[index[i]]->getSuit() << " " << 
                setw(2) << static_cast<int>(card[index[i]]->getCNum()) << " " << 
                setw(2) << static_cast<int>(card[index[i]]->getNum()) << " " << endl;
    }
    
    //Clean  up
    delete[] index;
    for (int i = 0; i < 52; i++) {
        delete[] card[i];
    }
    delete[] card;
    
    return 0;
}

