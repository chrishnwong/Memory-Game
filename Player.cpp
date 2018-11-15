#include "player.h"

Player(){
    _name = "Default";
    _side = Top;
    _rubyCount = 9999;
}

Player(string name, BoardSide side, int rubyCount = 0){
    _name = name
    _side = side;
    _rubyCount = 0;
}

string getName() const{
    return _name;
}

void setActive(bool flag){
    _active = flag;
}

bool isActive(){
    return _active;
}

int getNRubies() const{
    return _rubyCount;
}

void addReward(const Reward& r){
    //TODO
}

void setDisplayMode(bool endOfGame){
    _end = endOfGame;
}

string getEnumName() const{
    string str;

    switch _side {
        case Top:
            str = "Top";
        case Botttom:
            str = "Bottom";
        case Left:
            str = "Left";
        case Right:
            str = "Right";
        default:
            throw Exception("Bad BoardSide");
    }

    return str;
}

bool isEndOfGame() const{
    return _end;
}
