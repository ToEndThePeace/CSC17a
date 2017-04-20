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
#include "Move.h"
#include "Enemy.h"


class Encounter {
private:
    Player *p;
    Enemy *e;
    vector<Move> m;
    
    int pMV, eMV;
    
    //Integers to store numbers in after damage calculation
    int uDMG, eDMG, uHL, eHL, xpYield, loc;
    bool isWin, isLoss;
    
    //Integers to store enemy stats after level calculation
    int lvl, atk, mag, def, spd, cHP, mHP, cMP, mMP;
public:
    Encounter(Player &, Enemy &, vector<Move>&);
    
    void setEnStat(int); //Where int is a level to set stats to
    
    void turn();
    
    void output();
    void output(string);
};

Encounter::Encounter (Player &x, Enemy &y, vector<Move> &mv) {
    p = &x; //Referencing original player object
    e = &y;
    m = mv;
    isWin = false;
    isLoss = false;
    p->setStats();
    int newLvl;
    if (p->getLevel() < 10) {
        newLvl = rand() % p->getLevel();
    } else {
        newLvl = rand() % 6 + p->getLevel() - 4;
    }
    setEnStat(newLvl > 0 ? newLvl : 1); //Sets level within 3 of player lvl
    turn();
}

//Encounter class member functions
void Encounter::setEnStat(int l) {
    lvl = l;
    mHP = ceil(e->hp * 2 * lvl / 100) + 5 + lvl;
    mMP = ceil(e->mp * 2 * lvl / 100) + 5 + lvl;
    cHP = mHP;
    cMP = mMP;
    atk = ceil(e->atk * 2 * lvl / 100) + 5;
    mag = ceil(e->mag * 2 * lvl / 100) + 5;
    def = ceil(e->def * 2 * lvl / 100) + 5;
    spd = ceil(e->spd * 2 * lvl / 100) + 5;
    xpYield = ceil((e->isBoss() + 1) * e->xp * lvl / 7);
}

void Encounter::turn() {
    //Output so player can see enemy
    uDMG = 0;
    eDMG = 0;
    uHL = 0;
    eHL = 0;
    
    //Move selection phase
    int input, i(0);
    do {
        if (i == 1) output("Not enough mana.");
        output();
        cin.get();
        output("Select a move:");
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ": " << m[p->getMoves()[i]].name << ", " <<
                    m[p->getMoves()[i]].power << " POW, " <<
                    m[p->getMoves()[i]].heal << " HEAL, " <<
                    m[p->getMoves()[i]].cost << " MP" << endl;
        }
        cout << ">> ";
        cin >> input;
        input--;
        pMV = p->getMoves()[input];
        //cout << m[pMV].name << " " << m[pMV].power <<  endl;
        i = 1;
    } while (p->mp[0] < m[pMV].cost);
    do {
        input = rand() % 4;
        eMV = e->moves[input];
    } while (cMP < m[eMV].cost);
    
    cin.ignore(256, '\n');
    
    //Damage and healing calculation phase
    if (m[pMV].power != 0)
        uDMG = ceil(((float(2) * p->getLevel() + 10) / 250 * 
            (m[pMV].type == 0 ? p->getStats()[2] : p->getStats()[3]) / 
            def * m[pMV].power) + 2);
    if (m[pMV].heal != 0)
        uHL  = ceil(((float(2) * p->getLevel() + 10) / 250 *
            (m[pMV].type == 0 ? p->getStats()[2] : p->getStats()[3]) /
            p->getStats()[4] * m[pMV].heal) + 2);
    if (m[eMV].power != 0)
        eDMG = ceil(((float(2) * lvl + 10) / 250 *
            (m[eMV].type == 0 ? e->atk : e->mag) /
            p->getStats()[4] * m[eMV].power) + 2);
    if (m[eMV].heal != 0)
        eHL  = ceil(((float(2) * lvl + 10) / 250 *
            (m[eMV].type == 0 ? e->atk : e->mag) /
            def * m[eMV].heal) + 2);
    
    //Apply mana costs
    p->mp[0] -= m[pMV].cost;
    cMP      -= m[eMV].cost;  
    
    /*/Debugging Lines
    cout << p->getStats()[2] << " " << p->getStats()[3] << endl;
    cout << atk << " " << mag << endl;
    cout << uDMG << " " << uHL << " " << eDMG << " " << eHL << endl;//*/
    
    //Damage and healing application phase
    if (p->getStats()[5] >= spd) {
        //Player Heal Phase
        p->hp[0] = p->hp[0] + uHL;
        if (p->hp[0] > p->hp[1]) p->hp[0] = p->hp[1];
        if (uHL != 0) output("You healed for " + to_string(uHL) + " points!");
        
        //Player Damage Phase
        if (uDMG != 0) output("You deal " + to_string(uDMG) + " damage!");
        
        if (cHP - uDMG <= 0) {
            //If the game is lost, enemy gets no turn
            cHP = 0;
            isWin = true;
        } else { //Enemy's Turn
            //Enemy heal phase
            cHP = cHP + eHL;
            if (cHP > mHP) cHP = mHP;
            if (eHL != 0) output("Enemy healed for " + to_string(eHL) + " points!");
            
            //Enemy Damage Phase
            if (eDMG != 0) output("Enemy deals " + to_string(eDMG) + " damage!");
            if (p->hp[0] - eDMG <= 0) {
                p->hp[0] = 0;
                isLoss = true;
            } else {
                cHP -= uDMG;
                p->hp[0] -= eDMG;
            }
        }
    } else {
        //Enemy Heal Phase
        cHP = cHP + eHL;
        if (cHP > mHP) cHP = mHP;
        if (eHL != 0) output("Enemy healed for " + to_string(eHL) + " points!");
        
        //Enemy Damage Phase
        if (eDMG != 0) output("Enemy deals " + to_string(eDMG) + " damage!");
        
        if (p->hp[0] - eDMG <= 0) {
            //If the game is lost, player gets no turn
            p->hp[0] = 0;
            isLoss = true;
        } else { //Player's turn
            //Player heal phase
            p->hp[0] = p->hp[0] + uHL;
            if (p->hp[0] > p->hp[1]) p->hp[0] = p->hp[1];
            if (uHL != 0) output("You healed for " + to_string(uHL) + " points!");
            
            //Player Damage Phase
            if (uDMG != 0) output("You deal " + to_string(uDMG) + " damage!");
            if (cHP - uDMG <= 0) {
                cHP = 0;
                isWin = true;
            } else {
                cHP -= uDMG;
                p->hp[0] -= eDMG;
            }
        }
    }
    
    
    //What to do if battle is won or lost
    if (isWin) {
        output("You have vanquished your foe!");
        //Award XP
        p->addXP(xpYield);
        p->output();
        cin.get();
    } else if (isLoss) {
        output("You have been killed!");
        p->output();
        cin.get();
    } else {
        turn();
    }
}



void Encounter::output() {
    cout << setw(30) << left << p->getName() << setw(30) << right << e->getName() << endl <<
            
        "Lvl " << setw(3) << left << p->getLevel() << 
        setw(46) << left << " " + p->getRole() << "Lvl " << 
        setw(3) << right << lvl << endl <<

        "HP: " << setw(3) << right << p->hp[0] << "/" << 
                setw(3) << left << p->hp[1] << 
                setw(41) << right << "HP:" << 
                setw(4) << right << cHP << "/" << 
                setw(3) << right << mHP << endl <<

        "MP: " << setw(3) << right << p->mp[0] << "/" << 
                setw(3) << left << p->mp[1] << 
                setw(41) << right << "MP:" << 
                setw(4) << right << cMP << "/" << 
                setw(3) << right << mMP << endl;
    cin.get();
}
void Encounter::output(string s) {
    int l = s.length();
    string x = "";
    for (int i = 0; i < l + 8; i++) {
        x = x + "*";
    }
    cout << x << endl <<
            "* - " << s << " - *" << endl <<
            x << endl;
}

#endif /* ENCOUNTER_H */

