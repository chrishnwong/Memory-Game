#include <iostream>
#include "Player.h"

using namespace std;

string Player::getName() const {
    return name;
}

void Player::setActive(bool _active){
    active = _active;
}

bool Player::isActive() const{
    return active;
}

int Player:: getNRubies() const{
    return numRubies;
}

void Player::addReward(const Reward &reward){
    numRubies = numRubies + reward.getNRubies();
}

void Player::setDisplayMode(bool _endOfGame){
    endOfGame = _endOfGame;
}


Side Player::getSide() const{
    return side;
}

void Player::setSide(Side _side){
    side = _side;
}

ostream& operator<<(ostream& os, const Player& player) {
    if (player.endOfGame) {
        string side=player.getEnumSides[player.side];
        string activeStr = (player.active ? "active" : "inactive");

        os << player.name << ": " << side << " (" << activeStr << ")";
    } else {
        os << player.name << ": " << player.numRubies << " rubies";
    }
    return os;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
