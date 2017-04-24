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
#include "Loc.h"

//Global Constants
int NUM_LOCS = 6;
int NUM_ENS = 4;

//Function Prototypes
void journey(Player &, const vector<Loc> &, Enemy**, const vector<Move> &);

//Menu Functions
void newChar(vector<Player> &);
void loadChar(vector<Player> &, int &);
void delChar(vector<Player> &);

//File I/O Functions
vector <Player> loadPlayer();
vector <Move> loadMvs();
Enemy** loadEnemy();
vector <Loc> loadLocs();
void svPlyrs(vector<Player> &);

//Output Functions
void output(string);
void output(string, int);
void menuLine(int, string);
void inptLine(int &);
void inptLine(string &);
void mPause();

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
    //Load Map Data
    vector <Loc> map = loadLocs();
    
    int x(1); //Used for menu inputs
    
    output("Welcome to Rogue", 1);
    
    do {
        int curChar(-1); //Used to store current character index as session var
        
        if (x < 1 || x > 3) output("Invalid choice.");
        output("What would you like to do?");
        menuLine(1, "Create New Character");
        menuLine(2, "Load Character");
        menuLine(3, "Delete Character");
        menuLine(4, "Exit");
        inptLine(x);
        
        int input;
        switch (x) {
            case 1:
                newChar(play);
            case 2:
            {
                loadChar(play, curChar);
                int swt(1);
                do {
                    journey(play[curChar], map, enem, move);
                    output("Embark on another adventure?");
                    menuLine(1, "Yes");
                    menuLine(2, "No");
                    inptLine(swt);
                } while (swt == 1);
                break;
            }
            case 3:
                //delChar(play);
                for (int i = 0; i < NUM_LOCS; i++) {
                    for (int j = 0; j < NUM_ENS; j++) {
                        cout << enem[i][j].name << endl;
                    }
                }
                break;
            case 4:
                for (int i = 0; i < NUM_LOCS; i++) {
                    for (int j = 0; j < NUM_ENS; j++) {
                        cout << i << j << enem[i][j].name << endl;
                    }
                }
            default:
                break;
        } //*/
    } while (x != 4);

    //Cleanup Crew
    for (int i = 0; i < NUM_LOCS; i++) {
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
void journey(Player &p, const vector<Loc> &map, Enemy** enem, const vector<Move> &mv) {
    p.output();
    mPause();
    
    int input, l;
    
    output("Choose your adventure!");
    for (int i = 0; i < map.size(); i++) {
        if (map[i].lvl <= p.getLevel()) menuLine(i + 1, map[i].name);
    }
    inptLine(input);
    
    l = input - 1;
    output("You have arrived at the " + map[l].name + "!", 1);
    output("If you defeat 4 enemies, the boss will find you.");
    output("Tread lightly...");
    
    //Now we need 4 encounters with random enemies
    int count(0);
    bool isOver(false);
    int r = rand() % 3;
    /*do {
        //Encounter battle(p, enem[l][rand() % 3], mv); //Encounter constructor
        
        //If game is lost, breaks out of loop
        isOver = battle.isLoss;
    } while (!isOver && count < 4);*/
    
    //Now we need the boss
    if (!isOver) {
        cout << map[l].name << " " << l << " " << r << " " << enem[l][r].name << endl;
    }
}

void newChar(vector<Player> &v) {
    int input;
    
    do {
        output("Choose a Class:");
        menuLine(1, "Mage");
        menuLine(2, "Warrior");
        menuLine(3, "Rogue");
        inptLine(input);
    } while (input < 1 || input > 3);
    input--;
    int nRl = input;
    input = 1;
    string y;
    do {
        output("Enter a Name!");
        inptLine(y);
        output("Is \"" + y + "\" okay?");
        menuLine(1, "Yes");
        menuLine(2, "No");
        inptLine(input);
    } while (input != 1);
    
    //NOW I GOTTA SAVE THE NEW USER'S INFO
    Player nPl(y, nRl);
    v.push_back(nPl);
}
void loadChar(vector<Player> &v, int &cIndx) {
    int input(1);
    do {
        if (input != 1) output("Invalid choice.");
        output("Select a Character:");
        for (int i = 0; i < v.size(); i++) {
            menuLine(i + 1, v[i].getName());
        }
        inptLine(input);
    } while (input < 1 || input > v.size());
    input -= 1;
    
    cIndx = input;
}
void delChar(vector<Player> &v) {
    
}

//File I/O
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
    Enemy** ary = new Enemy*[NUM_LOCS];
    
    //Variables to read in file stream
    int loc, indx, hp, mp, atk, mag, def, spd, xp, m1, m2, m3, m4;
    bool boss;
    string race, cls;
    
    //Read in the file
    int count(0);
    while (binEnems >> loc >> indx >> race >> cls >> hp >> mp >> 
                       atk >> mag  >> def >> spd >> boss >> xp >>
                       m1 >> m2 >> m3 >> m4) {
        cout << loc << race << cls << endl;
        ary[loc] = new Enemy[NUM_ENS]();
        //for (int i = 0; i < NUM_ENS; i++) {
        ary[loc][indx - 4 * loc].setEnemy(loc, race, cls, hp, mp, atk, mag, 
                                          def, spd, boss, xp, indx, m1, m2, m3, m4);
        //}
        cout << ary[loc][indx - 4 * loc].name << endl;
    }
    
    binEnems.close();
    
    return ary;
}
vector<Loc> loadLocs() {
    //Open Binary File
    fstream binLocs;
    binLocs.open("lib/locList.bin", ios::in | ios::binary);
    
    //Create Vector of Locations
    vector<Loc> ary;
    
    //Variables to read in file stream
    int indx, lvl;
    string n1, n2;
    
    //Read in the file
    while (binLocs >> indx >> lvl >> n1 >> n2) {
        Loc nLoc(indx, lvl, n1, n2);
        ary.push_back(nLoc);
    }
    
    binLocs.close();
    
    return ary;
}
void svPlyrs(vector<Player> &v) {
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

/**
 * Used to display decorative system messages in console
 * @param s the string to display
 */
void output(string s, int p = 0) {
    int l = s.length();
    string x = "";
    for (int i = 0; i < l + 8; i++) {
        x = x + "*";
    }
    cout << x << endl <<
            "* - " << s << " - *" << endl <<
            x << endl;
    if (p == 1) mPause();
}
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
void menuLine(int n, string s) {
    cout << setw(2) << right << n << ": " << s << endl;
}
void inptLine(int &n) {
    cout << ">>> ";
    cin >> n;
}
void inptLine(string &n) {
    cout << ">>> ";
    cin >> n;
}
void mPause() {
    cin.ignore(256, '\n');
    cin.get();
}