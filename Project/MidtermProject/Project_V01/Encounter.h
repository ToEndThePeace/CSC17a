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

#include "Player.h"


class Encounter {
private:
    Player p;
    Enemy e;
    //Integers to store numbers in after damage calculation
    int uDMG, eDMG, xpYield, loc;
    
    //Integers to store enemy stats after level calculation
    int lvl, atk, mag, def, spd, cHP, mHP, cMP, mMP;
public:
    Encounter(Player &, Enemy &);
    
    void setEnStat(int); //Where int is a level to set stats to
    
    void doDmg();
    
    void output();
};

Encounter::Encounter (Player &x, Enemy &y) {
    p = x; //Referencing original player object
    e = y;
    int newLvl = rand() % 6 + p.getLevel() - 4;
    setEnStat(newLvl > 0 ? newLvl : 1); //Sets level within 3 of player lvl
    //Debugging
    uDMG = 5;
    eDMG = 5;
}

//Encounter class member functions
void Encounter::setEnStat(int l) {
    lvl = l;
    mHP = ceil(e.hp * 2 * lvl / 100) + 5 + lvl;
    mMP = ceil(e.mp * 2 * lvl / 100) + 5 + lvl;
    cHP = mHP;
    cMP = mMP;
    atk = ceil(e.atk * 2 * lvl / 100) + 5;
    mag = ceil(e.mag * 2 * lvl / 100) + 5;
    def = ceil(e.def * 2 * lvl / 100) + 5;
    spd = ceil(e.spd * 2 * lvl / 100) + 5;
}

void Encounter::doDmg() {
    p.hp[0] = p.hp[0] - eDMG <= 0 ? 0 : p.hp[0] - eDMG;
    cHP = cHP - uDMG <= 0 ? 0 : cHP - uDMG;
}



void Encounter::output() {
    cout << setw(30) << left << p.getName() << setw(30) << right << e.getName() << endl <<
            
        "Lvl " << setw(3) << left << p.getLevel() << 
        setw(46) << left << " " + p.getRole() << "Lvl " << 
        setw(3) << right << lvl << endl <<

        "HP: " << setw(3) << right << p.hp[0] << "/" << 
                setw(3) << left << p.hp[1] << 
                setw(41) << right << "HP:" << 
                setw(4) << right << cHP << "/" << 
                setw(3) << right << mHP << endl <<

        "MP: " << setw(3) << right << p.mp[0] << "/" << 
                setw(3) << left << p.mp[1] << 
                setw(41) << right << "MP:" << 
                setw(4) << right << cMP << "/" << 
                setw(3) << right << mMP << endl;
}

#endif /* ENCOUNTER_H */

