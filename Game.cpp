#include "Game.h"


int getRound(){

}

void addPlayer(const Player& p){
    _p.push_back(p);
}

Player& getPlayer(Side s){
    for (auto& elem: _p) {
        if(&elem.getSide()==s)
            return &elem;
    }
}

const Card* getCurrentCard(){

}

void setCurrentCard(const Card* c){

}

Game& Game::operator << (const Game& g){

    return *this;
}
