#ifndef player_H
#define player_H

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::endl;
using std::ostream;

class Reward;

enum class BoardSide {
    Top,
    Bottom,
    Left,
    Right
};

class Player {
    string _name;
    enum BoardSide _side;
    int _rubyCount;
    bool _active;
    bool _end;//Does this belong here?

    public:
    Player();
    Player(string name, BoardSide side);
    string getName() const;
    void setActive(bool flag);
    bool isActive();
    int getNRubies() const;
    void addReward(const Reward& r);
    void setDisplayMode(bool endOfGame);

    string getEnumName() const;
    bool isEndOfGame() const;
};


ostream& operator << (ostream& os, const Player& p);

#endif
