#include <iostream>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(int _gameVersion, int numPlayers): gameVersion(_gameVersion){
    players.reserve(numPlayers);
    previousCard = 0;
    currentCard = 0;

    //players.reserve(numPlayers);
    //board = _board;
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
    board.reset();
    round++;
}

void Game::addPlayer(const Player& p) {
    players.push_back(p);

}

Player& Game::getPlayer(Side side) {
    for(vector<Player>::iterator it = players.begin(); it != players.end(); ++it){
        if(it->getSide() == side){
            return *it;
        }
//        }else{
//            return nullptr;
//        }
    }
    /*for(int i = 0;i < players.size(); i++){
        if(players.at(i).getSide() == side)
            return getPlayerVector->at(i);
    }*/

}

const Card* Game::getPreviousCard()const {
    return previousCard;
}

const Card* Game::getCurrentCard()const{
    return currentCard;
}

void Game::setCurrentCard(const Card* c) {
    if (previousCard == nullptr)
        previousCard = c;
    else
        previousCard = currentCard;
    currentCard = c;

}

Card* Game::getCard(const Letter& let, const Number& num){
    return board.getCard(let, num);
}

void Game::setCard(const Letter& let, const Number& num, Card* c){
    board.setCard(let, num, c);
    // why is a void type returning
}

//Board Game::getBoard() {
//    return board;
//}
//
//void Game::setBoard(Board b){
//    board = b;
//}

//string Game::toString() const {
//    return "";
//}

void Game::setCardDeck(CardDeck* _cards){
    cards = _cards;
}

//Board& Game::getBoard() const{
//    return *board;
//}

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


ostream& operator<<(ostream& os, const Game& game) {
    //os << board;
    return os;
}
