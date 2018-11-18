#include "Player.h"

Player::Player(){
    _name = "Default";
    _side = Side::Top;
    _rubyCount = 9999;
}

Player::Player(string n, Side s){
    _name = n;
    _side = s;
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
    //TODO
}

Side Player::getSide(){
    return _side;

}

void Player::setSide(Side s){
    _side = s;

}

Player& Player::operator << (const Player& p){
    /*

    if(p.isEndOfGame())
        os << p.getName() << ": " << p.getEnumName() << endl << endl;
    else
        os << p.getName() << ": " << p.getNRubies() << " rubies" << endl << endl;
*/
//TODO
    return *this;
}
