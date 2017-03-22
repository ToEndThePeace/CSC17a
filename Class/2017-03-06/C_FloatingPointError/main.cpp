/* 
 * Name: Brandon Ramirez
 * Date: March 3, 2017
 * In-Class Examples
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float sum = 0, frac = 0.3f;
    int nLoops = 10000000;
    
    for (int i = 1; i <= nLoops; i++) {
        sum += frac;
    }
    
    cout << "Expected Results: " << nLoops << " x " << frac << " = " <<
            nLoops * frac << endl <<
            "The computer gets an error: " << sum << endl <<
            "Percentage Error: " << (1 - sum / (nLoops * frac)) * 100 <<
            "%" << endl;
    return 0;
}

