/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: rcc
 *
 * Created on April 5, 2017, 1:20 PM
 */

#ifndef CARD_H
#define CARD_H

class Card {
private:
    unsigned char cNumber;
public:
    Card(unsigned char);
    char getSuit();
    char getFVal();
    char getNum();
    char getCNum();
};


#endif /* CARD_H */

