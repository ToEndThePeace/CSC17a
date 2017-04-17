#ifndef PLAYER_H
#define PLAYER_H


class Player {
private:
    std::string name;   //This needs to be a string
    int role;           //Use switch statements on the int
    vector <int> stats, bstats;
    int xp, level;
public:
    Player();
    Player(string, int);
    Player(string, int, int, int, int, int);
    
    vector <int> hp, mp; //Have 2 values, current and max
    
    int toNextLvl();
    void addXP(int);
    void setStats();
    
    //Accessor Members
    string getName();
    string getRole();
    int getLevel();
    vector <int> getStats();
    
    void output();
};

//Class Constructor
Player::Player() {
}
Player::Player(string s, int n, int cHP = 0, int cMP = 0,
               int cXP = 0, int l = 0) {
    name = s;
    role = n;
    level = l;
    xp = cXP;
    for (int i = 0; i < 6; i++) {
        bstats.push_back(0);
        stats.push_back(0);
    }
    for (int i = 0; i < 2; i++) {
        hp.push_back(0);
        mp.push_back(0);
    }
    setStats();
}
//Member Function Definitions
/**
 * Returns the amount of XP required to reach the next level
 * @return 
 */
int Player::toNextLvl() { 
    return pow(level, 3);
}
/**
 * Adds XP to a character and levels up if enough XP was earned
 * @param n //The amount of experience gained
 */
void Player::addXP(int n) {
    xp = xp + n;
    while (xp >= toNextLvl()) { //If you have enough XP to hit the next level //Increment your level
        level++;
        cout << "You have reached level " << level << endl; //Debugging
    }
}
void Player::setStats() {
    switch (role) {
        case 0: //Role 0: Mage
            bstats[0] = 65;
            bstats[1] = 80;
            bstats[2] = 40;
            bstats[3] = 80;
            bstats[4] = 50;
            bstats[5] = 40;
            break;
        case 1: //Role 1: Warrior
            bstats[0] = 70;
            bstats[1] = 45;
            bstats[2] = 75;
            bstats[3] = 35;
            bstats[4] = 60;
            bstats[5] = 55;
            break;
        case 2: //Role 2: Rogue
            bstats[0] = 60;
            bstats[1] = 60;
            bstats[2] = 80;
            bstats[3] = 80;
            bstats[4] = 30;
            bstats[5] = 70;
            break;
    }
    for (int i = 0; i < 2; i++) {
        stats[i] = ceil(bstats[i] * 2 * level / 100) + 10 + level;
    }
    for (int i = 2; i < 6; i++) {
        stats[i] = ceil(bstats[i] * 2 * level / 100) + 5;
    }
    hp[0] = stats[0];
    hp[1] = stats[0];
    mp[0] = stats[1];
    mp[1] = stats[1];
}

//Accessor Member Function Definitions
string Player::getName() {
    return name;
}
int Player::getLevel() {
    return level;
}
string Player::getRole() {
    switch(role) {
        case 0: 
            return "Mage";
        case 1:
            return "Warrior";
        case 2:
            return "Rogue";
        default:
            return "Unknown";
    }
}
vector <int> Player::getStats() {
    return stats;
}
void Player::output() {
    cout << name << ", Level " << level << " " << getRole() << endl <<
            "Max HP: " << stats[0] << ", Max MP: " << stats[1] << endl <<
            "ATK: " << stats[2] << endl <<
            "MAG: " << stats[3] << endl <<
            "DEF: " << stats[4] << endl <<
            "SPD: " << stats[5] << endl;
}

#endif /* PLAYER_H */

