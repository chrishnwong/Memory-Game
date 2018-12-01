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
    return nRubies;
}

void Player::addReward(const Reward &reward){
    nRubies += reward.getNRubies();
}

void Player::setDisplayMode(bool _endOfGame){
    endOfGame = _endOfGame;
}

Side Player::getSide(){
    return side;
}

void Player::setSide(Side _side){
    side = _side;
}

ostream& operator<<(ostream& os, const Player& player) {
    if (player.endOfGame) {
        string side=player.getEnumSides[player.side];

        switch (player.side) {
            case 0:
                side = "top";
                break;
            case 1:
                side = "left";
                break;
            case 2:
                side = "bottom";
                break;
            case 3:
                side = "right";
                break;
            default:
                break;
        }//project told us to avoid using switch cases*/

        string activeStr = (player.active ? "active" : "inactive");

        os << player.name << ": " << side << " (" << activeStr << ")";
    } else {
        os << player.name << ": " << player.nRubies << " rubies";
    }
    return os;
}
