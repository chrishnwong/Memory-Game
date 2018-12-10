#include <iostream>
#include "Player.h"
#include "RewardDeck.h"

//#define PLAYER_TEST;

#ifdef PLAYER_TEST
int main(){
    Player p = ("test", Side::top)
    cout << "Creating player with name test and on top side" << endl;

    p.setActive(true);
    cout << "Setting test as active" << endl;

    if(p.isActive()){
        cout << "test is active" << endl;
    }
    else{
        cout << "test is inactive, something is wrong" << endl;
    }

    cout << "Printing test's name, output should be test" << endl;
    cout << p.getName() << endl;

    cout << "Printing test when not end of game" << endl;
    cout << p << endl;

    cout << "Printing number of Rubies for test" << endl;
    cout<< p.getNRubies();<<endl;

    Deck<Reward> rewardDeck = RewardDeck::make_RewardDeck();

    Reward *reward = rewardDeck.getNext();

    p.addReward(*reward);
    cout << "Adding reward to test" << endl;


    p.setDisplayMode(true);
    cout << "Setting DisplayMode to end of game" << endl;

    cout << "Printing test when end of game" << endl;
    cout << p << endl;


    if(p.getSide()==Side::top){
        cout << "test is top side" << endl;
    }
    else{
        cout << "test is not top side, something is wrong" << endl;
    }

    cout << "Setting test side to bottom" << endl;
    p.setSide(Side::Bottom);

    if(p.getSide()==Side::bottom){
        cout << "test is bottom side" << endl;
    }
    else{
        cout << "test is not bottom side, something is wrong" << endl;
    }

    cout << "This concludes the public method tests for Player.cpp" << endl;
}
#endif

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
/*Player& Player::operator=(const Player& p){
    this->name = p.getName();
    this->nRubies = p.getNRubies();
    this->active = p.isActive();;
    //this.endOfGame = p.;
    this->side = p.getSide();

    return *this;
}*/

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
