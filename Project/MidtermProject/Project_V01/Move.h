/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Move.h
 * Author: brandon
 *
 * Created on April 17, 2017, 8:43 PM
 */

#ifndef MOVE_H
#define MOVE_H

class Move {
public:
    int power, heal, cost; //Index, power, cost of move
    bool type; //where T is ATK and F is MAG
    std::string name; //Name of the move
    //Constructors
    Move();
    Move(std::string, int, int, bool, int);
};

//Class Constructors
Move::Move() {}
Move::Move(std::string a, int b, int c, bool d, int e) {
    name = a;
    power = b;
    heal = c;
    type = d;
    cost = e;
}


#endif /* MOVE_H */

