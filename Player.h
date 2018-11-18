#ifndef player_H
#define player_H

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::endl;
using std::ostream;

class Reward;

enum Side {
    Top,
    Bottom,
    Left,
    Right
};

class Player {
    string _name;
    Side _side;
    int _rubyCount;
    bool _active;

    public:
    Player();
    Player(string n, Side s);
    string getName() const;
    void setActive(bool flag);
    bool isActive();
    int getNRubies() const;
    void addReward(const Reward& r);
    void setDisplayMode(bool endOfGame);
    Side getSide();
    void setSide(Side s);

    Side getSide() const;
    Player& operator << (const Player& p);
};

#endif
