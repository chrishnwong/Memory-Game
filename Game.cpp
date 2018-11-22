#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"

Game::Game(int _gameVersion, int numPlayers): gameVersion(_gameVersion){
    players.reserve(numPlayers);
    previousCard = 0;
    currentCard = 0;
    board = Board();
    //players
    //cards
    round = 0;
    gameVersion = _gameVersion;
    
}

Game::~Game() {

}

int Game::getRound() const {
    return round;
}

void Game::addPlayer(const Player& p) {
    players.push_back(p);

}

Player& Game::getPlayer(Side side) {
    for(std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it){
        if(it->getSide() == side){
            return *it;
        }
//        }else{
//            return nullptr;
//        }
    }

}

const Card* Game::getPreviousCard() const {
    return previousCard;
}

const Card* Game::getCurrentCard() const {
    return currentCard;
}

void Game::setCurrentCard(const Card* c) {
    //if (previousCard == nullptr)
    delete previousCard;
    previousCard = currentCard;
    currentCard = c;

}

Card* Game::getCard(const Letter& let, const Number& num){
    return board.getCard(let, num);
}

void Game::setCard(const Letter& let, const Number& num, Card* c){
    return board.setCard(let, num, c);
    // why is a void type returning
}

void Game::setBoard(Board b){
    board = b;
}

//string Game::toString() const {
//    return "";
//}

ostream& operator<<(ostream& os, const Game& game) {
    //os << board.toString();
    return os;
}
