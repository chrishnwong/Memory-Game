#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(int _gameVersion, int numPlayers): gameVersion(_gameVersion){
    players.reserve(numPlayers);
    previousCard = 0;
    currentCard = 0;

    round = 1;
    gameVersion = _gameVersion;

    current = 0;
}

Game::~Game() {

}

int Game::getRound() const {
    return round;
}

void Game::nextRound(){
    setCurrentCard(nullptr);
    setCurrentCard(nullptr);
    //resetPlayers();
    board.reset();
    round++;
}

void Game::resetPlayers(){
    for(auto i:players)
        i.setActive(true);
}

void Game::addPlayer(const Player& p) {
    players.push_back(p);

}

Player& Game::getPlayer(Side side) {
    for(vector<Player>::iterator it = players.begin(); it != players.end(); ++it){
        if(it->getSide() == side){
            return *it;
        }

    }


}

const Card* Game::getPreviousCard()const {
    return previousCard;
}

const Card* Game::getCurrentCard()const{
    return currentCard;
}

void Game::setCurrentCard(const Card* c) {
    if (previousCard == nullptr){
        previousCard = c;
    }else{
        previousCard = currentCard;
    }
    currentCard = c;

}

Card* Game::getCard(const Letter& let, const Number& num){
    return board.getCard(let, num);
}

void Game::setCard(const Letter& let, const Number& num, Card* c){
    board.setCard(let, num, c);

}



void Game::setCardDeck(CardDeck* _cards){
    cards = _cards;
}



const vector<Player>* Game::getPlayerVector() const{
    return &players;
}

bool Game::sortRubies(const Player& i, const Player& j){
    return i.getNRubies()>j.getNRubies();
}

void Game::getPlacements(){

    int i = 0;
    sort(players.begin(),
         players.end(),
         [](const Player& lhs, const Player& rhs)
         {
             return lhs.getNRubies() > rhs.getNRubies();
         });

    cout<<"The game has ended, here are the placements:"<<endl<<endl;


    for(Player &p : players){
        cout << place[i] << " - " << p << endl;
        i++;
    }

    cout << endl << "Thank you for playing!" << endl;
}

void Game::clearScreen(){
    string s;
    cout << "Press any key to continue... ";
    cin >> s;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

Player& Game::getNextPlayer(){
    current++;
    current=current%players.size();
    return getPlayer((Side) current);
}

void Game::resetCurrent(){
    current = 0;
}




//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
