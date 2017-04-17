/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: brandon
 *
 * Created on April 15, 2017, 4:12 PM
 */

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int loc;
    std::string race, cls;
    bool boss;
public:
    int hp, mp, atk, mag, def, spd, xp;
    Enemy();
    Enemy(int, int);
    void setEnemy(int, string, string, int, int, int, int, int, int, bool, int);
    //Debugging functions
    int getLoc();
    string getName();
};

Enemy::Enemy() {
    int loc(0);
    std::string race("Goblin"), cls("Warrior");
    int hp(60), mp(40), atk(50), mag(40), def(50), spd(50);
}
void Enemy::setEnemy(int a, string b, string c, int d, int e, int f, int g,
                     int h, int i, bool j, int k) {
    loc = a;
    race = b;
    cls = c;
    hp = d;
    mp = e;
    atk = f;
    mag = g;
    def = h;
    spd = i;
    boss = j;
    xp = k;
}

int Enemy::getLoc() {
    return loc;
}
string Enemy::getName() {
    return race + " " + cls;
}

#endif /* ENEMY_H */

