/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Loc.h
 * Author: brandon
 *
 * Created on April 22, 2017, 3:56 PM
 */

#ifndef LOC_H
#define LOC_H

#include "Encounter.h"


struct Loc {
    int indx, lvl;
    std::string name;
    Loc(int, int, std::string, std::string);
};

Loc::Loc(int a, int b, std::string c, std::string d) {
    indx = a;
    lvl = b;
    name = c + ' ' + d;
}

#endif /* LOC_H */

