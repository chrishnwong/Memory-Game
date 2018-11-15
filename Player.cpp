#include "player.h"

Player::Player(){
    _name = "Default";
    _side = BoardSide::Top;
    _rubyCount = 9999;
}

Player::Player(string name, BoardSide side){
    _name = name;
    _side = side;
    _rubyCount = 0;
}

string Player::getName() const{
    return _name;
}

void Player::setActive(bool flag){
    _active = flag;
}

bool Player::isActive(){
    return _active;
}

int Player::getNRubies() const{
    return _rubyCount;
}

void Player::addReward(const Reward& r){
    //TODO
}

void Player::setDisplayMode(bool endOfGame){
    _end = endOfGame;
}

string Player::getEnumName() const{
    string str;

    switch (_side) {
        case BoardSide::Top:
            str = "Top";
        case BoardSide::Bottom:
            str = "Bottom";
        case BoardSide::Left:
            str = "Left";
        case BoardSide::Right:
            str = "Right";
        default:
            str = "Unknown side";
    }

    return str;
}

bool Player::isEndOfGame() const{
    return _end;
}

ostream& operator << (ostream& os, const Player& p){
    if(p.isEndOfGame())
        os << p.getName() << ": " << p.getEnumName() << endl << endl;
    else
        os << p.getName() << ": " << p.getNRubies() << " rubies" << endl << endl;

    return os;
}
