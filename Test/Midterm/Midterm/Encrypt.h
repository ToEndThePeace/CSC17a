/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Encrypt.h
 * Author: brandon
 *
 * Created on April 24, 2017, 9:02 PM
 */

#ifndef ENCRYPT_H
#define ENCRYPT_H

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void encrypt(string &s) {
    for (int i = 0; i < 4; i++) {
        int x = static_cast<int>(s[i]);
        x = (x + 3) % 8;
        s[i] = x + '0';
    }
    swap(s[0], s[1]);
    swap(s[2], s[3]);
}
void decrypt(string &s) {
    swap(s[0], s[1]);
    swap(s[2], s[3]);
    for (int i = 0; i < 4; i++) {
        int x = static_cast<int>(s[i]);
        x = (x + 5) % 8; //Pretty much the inverse operation
        s[i] = x + '0';
    }
}
bool canEncrypt(string s) {
    for (int i = 0; i < 4; i++) {
        if (s[i] > '7') return false;
    }
    return true;
}

#endif /* ENCRYPT_H */

