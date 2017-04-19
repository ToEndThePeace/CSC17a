//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

//User Libraries
#include "Player.h"
#include "Enemy.h"
#include "Move.h"
#include "Encounter.h"

//Global Constants
int NUM_RACES = 6;
int NUM_TYPES = 3;

//Function Prototypes

//File I/O Functions
vector <Player> loadPlayer();
vector <Move> loadMvs();
Enemy** loadEnemy();
void newEnemy();
void svPlyrs(vector<Player>);

//Output Functions
void output(string);

//Main Program
int main(int argc, char** argv) {
    //Set Random Seed
    srand(time(0));
    
    //Load Enemy Data
    Enemy** enem = loadEnemy();
    //Load Enemy Moves
    vector <Move> move = loadMvs();
    //Load Player Data
    vector <Player> play = loadPlayer();
    
    
    int x; //Used for menu inputs
    
    output("Rogue");
    
    output("What would you like to do?");
    cout << "1: Load Existing Character" << endl <<
            "2: Create New Character" << endl <<
            "3: Exit" << endl <<
            "4: New Enemy" << endl <<
            "5: Output Enemy Names" << endl <<
            "6: Random Encounter" << endl <<
            "7: Output Player List" << endl <<
            "8: New Encounter" << endl <<
            ">> ";
    cin >> x;
    int input;
    switch (x) {
        case 1:
            output("Which character?");
            for (int i = 0; i < play.size(); i++) {
                cout << i + 1 << ": " << play[i].getName() << endl;
            }
            cout << ">> ";
            cin >> input;
            play[input - 1].output();
            break;
        case 2:
            cout << "Creating character..." << endl;
            break;
        case 3:
            cout << "Peace out, fam." << endl;
            break;
        case 4:
            newEnemy();
            break;
        case 5:
            for (int i = 0; i < NUM_RACES; i++) {
                for (int j = 0; j < NUM_TYPES; j++) {
                    cout << enem[i][j].getName() << endl;
                }
            }
            break;
        case 6:
        {
            int rLoc = rand() % NUM_RACES;
            int rEnm = rand() % NUM_TYPES;
            output(enem[rLoc][rEnm].getName());
            break;
        }
        case 7:
            for (int i = 0; i < play.size(); i++) {
                cout << play[i].getName() << ", Level " << play[i].getLevel() <<
                        endl;
            }
            break;
        case 8:
        {
            char yorn('y');
            do {
                Encounter battle(play[/*rand() % play.size()*/1], 
                        enem[rand() % NUM_RACES][rand() % NUM_TYPES], move);
                output("Play again? y/n");
                cout << ">> ";
                cin >> yorn;
            } while (yorn != 'n');
            break;
        }
        default:
            break;
    } //*/

    //Cleanup Crew
    for (int i = 0; i < NUM_RACES; i++) {
        delete[] enem[i];
    }
    delete[] enem;
    
    output("Saving characters...");
    
    svPlyrs(play);
    
    output("Thanks for playing!");
    
    //End Run
    return 0;
}

//Function Declarations
vector <Move> loadMvs() {
    //Open lib file
    fstream binMvs;
    binMvs.open("lib/movelist.bin", ios::in | ios::binary);
    
    //Create vector of moves
    vector <Move> ary;
    
    //Variables to read in file stream
    int pow, heal, cost;
    string name;
    bool type;
    
    //Read in the file
    while (binMvs >> name >> pow >> heal >> type >> cost) {
        Move m(name, pow, heal, type, cost);
        ary.push_back(m);
    }
    
    binMvs.close();
    
    return ary;
}
vector <Player> loadPlayer() {
    //Open Library File
    fstream binPlays;
    binPlays.open("lib/playerList.bin", ios::in | ios::binary);
    
    //Create vector of players
    vector<Player> ary;
    
    //Variables to read in file stream
    string name;
    int role, hp, mp, xp, lvl;
    
    //Read in the file
    while (binPlays >> name >> role >> hp >> mp >> xp >> lvl) {
        //cout << name << ", Level " << lvl << endl;//Debugging
        Player nPL(name, role, hp, mp, xp, lvl);
        ary.push_back(nPL);
    }
    
    binPlays.close();
    
    return ary;
}
/**
 * Loads the list of enemies into a 2D array of objects and returns that array
 * @return the 2D array
 */
Enemy** loadEnemy() {
    //Open library file
    fstream binEnems;
    binEnems.open("lib/enemyList.bin", ios::in | ios::binary);
    
    //Create 2d pointer array of enemies
    Enemy** ary = new Enemy*[NUM_RACES];
    
    //Variables to read in file stream
    int loc, indx, hp, mp, atk, mag, def, spd, xp, m1, m2, m3, m4;
    bool boss;
    string race, cls;
    
    //Read in the file
    while (binEnems >> loc >> indx >> race >> cls >> hp >> mp >> 
                       atk >> mag  >> def >> spd >> boss >> xp >>
                       m1 >> m2 >> m3 >> m4) {
        //cout << loc << race << cls << endl;
        ary[loc] = new Enemy[NUM_TYPES];
        for (int i = 0; i < NUM_TYPES; i++) {
            ary[loc][i].setEnemy(loc, race, cls, hp, mp, atk, mag, 
                                 def, spd, boss, xp, indx, m1, m2, m3, m4);
        }
    }
    
    binEnems.close();
    
    return ary;
}
/**
 * Adds a new enemy to the enemyList.bin file until user says stop
 */
void newEnemy() {
    //Open Data File
    fstream binEnems;
    binEnems.open("lib/enemyList.bin", ios::in     | ios::out | 
                                       ios::binary | ios::app);
    string text;
    char input('y');
    while (input == 'y') {
        string loc, race, cls, hp, mp, atk, mag, def, spd;
        cout << "Loc: ";
        cin >> loc;
        cout << "Race: ";
        cin >> race;
        cout << endl << "Class: ";
        cin >> cls;
        cout << endl << "HP: ";
        cin >> hp;
        cout << endl << "MP: ";
        cin >> mp;
        cout << endl << "ATK: ";
        cin >> atk;
        cout << endl << "MAG: ";
        cin >> mag;
        cout << endl << "DEF: ";
        cin >> def;
        cout << endl << "SPD: ";
        cin >> spd;
        string text = loc + " " + race + " " + cls + " " + hp + " " + mp + " " +
                atk + " " + mag + " " + def + " " + spd + "\n";
        binEnems.write(text.c_str(), text.size());
        cout << "Again? ";
        cin >> input;
    }
    
    //Close data file
    binEnems.close();
}
/**
 * Used to display decorative system messages in console
 * @param s the string to display
 */
void output(string s) {
    int l = s.length();
    string x = "";
    for (int i = 0; i < l + 8; i++) {
        x = x + "*";
    }
    cout << x << endl <<
            "* - " << s << " - *" << endl <<
            x << endl;
}

void svPlyrs(vector<Player> v) {
    //Open the binary file for output
    fstream playOut;
    playOut.open("lib/playerList.bin", ios::out | ios::binary | ios::trunc);
    
    //Write file
    for (int i = 0; i < v.size(); i++) {
        playOut << v[i].getName() << " " << v[i].gRlNum() << " " <<
                v[i].hp[0] << " " << v[i].mp[0] << " " << v[i].getXP() << " " <<
                v[i].getLevel() << "\n";
    }
    
    playOut.close();
}