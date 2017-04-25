/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statsResult.h
 * Author: rcc
 *
 * Created on April 24, 2017, 2:10 PM
 */
#ifndef STATSRESULT_H
#define STATSRESULT_H

struct statsResult {
    //The original data list
    int *data;
    int size;
    
    float avg, median;
    int *mode;
    int nModes, maxFreq;
    
    statsResult();
    statsResult(int *, int);
    void output();
};
statsResult::statsResult() {
    avg = 0;
    nModes = 0;
    maxFreq = 0;
}
statsResult::statsResult(int *ary, int n) {
    avg = 0;
    nModes = 0;
    maxFreq = 0;
    
    data = new int[n];
    for (int i = 0; i < n; i++) {
        data[i] = ary[i];
    }
    size = n;
}
void statsResult::output() {
   cout << "Analysis of List: " << endl <<
            "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i != size - 1) cout << ", ";
    }
    cout << "]" << endl <<
            "Average:        " << avg << endl <<
            "Median:         " << median << endl <<
            "Mode(s):        ";
    for (int i = 0; i < nModes; i++) {
        cout << mode[i];
        if (i != nModes - 1) cout << ", ";
    }
    cout << endl <<
            "Mode Frequency: " << maxFreq << endl;
}

statsResult *avgMedMode(int *ary, int n) {
    statsResult *res = new statsResult(ary, n);
    
    //Calculate Average
    int sum(0);
    for (int i = 0; i < n; i++) {
        sum += ary[i];
    }
    res->avg = static_cast<float>(sum) / n;
    
    //Calculate Median
    if (n % 2 == 0) { //Even number of ints
        res->median = (ary[(n + 1) / 2] + ary[(n - 1) / 2]) / static_cast<float>(2);
    } else { //Odd number of ints
        res->median = ary[n / 2];
    }
    
    //Calculate Mode(s)
    vector<int> a(1, 0), b(1, 0); //Modes and frequency, respectively
    
    //This loop finds all potential modes and stores them 
    //and their frequencies into vectors
    /*for (int i = 0; i < n; i++) { //the whole array input
        for (int j = 0; j < i; j++) { //the array searched so far
            if (ary[i] == ary[j]) { //If number has already been seen
                if (a.empty()) { //First potential mode found
                    a.push_back(ary[i]);
                    b.push_back(1);
                } else { //Any modes found after that
                    for (int x = 0; x < a.size(); x++) {
                        if (a[x] == ary[i]) { //If mode already exists
                            //Increment the respective mode frequency
                            b[x]++;
                        } else { //If first time finding this mode
                            a.push_back(ary[i]);
                            b.push_back(1);
                        }
                    }
                }
            }
        }
    }*/
    for (int i = 0; i < n; i++) {//To iterate over each array value
        for (int j = 0; j < i; j++) {//To check each value against all past values
            if (ary[i] == ary[j]) {//Found a match
                if (b[0] == 0) {//If no mode frequency has been found (first mode))
                    a[0] = ary[i];
                    b[0] = 2;
                } else {
                    for (int x = 0; x < a.size(); x++) {//Check if mode has been found already
                        if (a[x] == ary[i]) {//Mode is already in vector
                            b[x]++;
                            x = a.size();
                        } else if (x == a.size() - 1) {//It's not, so we add a new entry
                            a.push_back(ary[i]);
                            b.push_back(1);
                        }
                    }
                }
                j = i;
            }
        }
    }
    /* Debugging
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << '(' << b[i] << ") ";
    }
    cout << endl;
     * */
    
    //This loop aims to find the maxFreq and number of modes
    res->maxFreq = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] > res->maxFreq) {
            res->maxFreq = b[i];
            res->nModes = 1;
        } else if (b[i] == res->maxFreq) {
            res->nModes++;
        }
    }
    
    res->mode = new int[res->nModes];
    int c(0); //Index for mode array
    
    //This loop finds all the modes with the maxFreq and stores them in *mode
    for (int i = 0; i < a.size(); i++) {
        if (b[i] == res->maxFreq) {
            res->mode[c] = a[i];
            c++;
        }
    }
    
    res->output();
    
    return res;
}

#endif /* STATSRESULT_H */

