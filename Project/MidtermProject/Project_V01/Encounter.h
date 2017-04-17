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
    int uDMG, eDMG, xpYield, loc;
    
    //Integers to store enemy stats after level calculation
    int lvl, atk, mag, def, spd, cHP, mHP, cMP, mMP;
public:
    Encounter(Player &, Enemy &);
    
    void setEnStat(int); //Where int is a level to set stats to
    
    void output();
};

Encounter::Encounter (Player &x, Enemy &y) {
    p = x; //Referencing original player object
    e = y;
    setEnStat(rand() % 6 + p.getLevel() - 3); //Sets level within 3 of player lvl
}

//Encounter class member functions
void Encounter::setEnStat(int l) {
    
}

/*void Encounter::output() {
    cout << setw(40) << left << p.getName() << setw(40) << right << e.getName()
            << endl <<
            setw(40) << left << "Lvl " + p.getLevel() + " " + p.getRole() <<
            setw(40) << right << "Lvl " + lvl
            << endl <<
            setw(20) << left << "HP: " + p.gHP() + " / " + p.getStats()[0] <<
            setw(10) << " " << //Empty
            setw(20) << " " << //Should later read out location of battle
            setw(10) << " " <<
            setw(20) << right << "HP: " + cHP + " / " + mHP
            << endl <<
            setw(20) << left << "MP: " + p.gMP() + " / " + p.getStats()[1] <<
            setw(40) << " " <<
            setw(20) << right << "MP: " + cMP + " / " + mMP
            << endl;
}*/

#endif /* ENCOUNTER_H */

