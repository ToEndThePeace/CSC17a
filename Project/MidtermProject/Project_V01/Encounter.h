/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Encounter.h
 * Author: brandon
 *
 * Created on April 14, 2017, 8:28 PM
 */

#ifndef ENCOUNTER_H
#define ENCOUNTER_H

class Encounter {
private:
    Player p;
    Enemy e;
    //Integers to store numbers in after damage calculation
    int uDMG, eDMG, xpYield;
public:
    Encounter(Player &, Enemy);
};

Encounter::Encounter (Player &x, Enemy y) {
    p = x; //Referencing original player object
    e = y;
}

//Encounter class member functions

#endif /* ENCOUNTER_H */

