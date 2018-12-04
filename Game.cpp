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

    players.reserve(numPlayers);
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

void Game::incRound(){
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

}

const Card* Game::getPreviousCard()const {
    return previousCard;
}

const Card* Game::getCurrentCard()const{
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
    sort(players.begin(), players.end());

    cout<<"The game has ended, here are the placements:"<<endl<<endl;


    for(Player &p : players){
        cout << place[i] << " - " << p.getName() << " with " << p.getNRubies() << " Rubies" << endl;
        i++;
    }

    cout << endl << "Thank you for playing!" << endl;
}

void Game::threeCardReveal(Side side){
    string arr[3] = {"","",""};

    switch (side) {
        case Side::top:
        board.getCard((Letter) A, (Number) TWO)->printCard(arr);
        board.getCard((Letter) A, (Number) THREE)->printCard(arr);
        board.getCard((Letter) A, (Number) FOUR)->printCard(arr);
        break;
    case Side::left:
        board.getCard((Letter) B, (Number) ONE)->printCard(arr);
        board.getCard((Letter) C, (Number) ONE)->printCard(arr);
        board.getCard((Letter) D, (Number) ONE)->printCard(arr);
        break;
    case Side::bottom:
        board.getCard((Letter) E, (Number) TWO)->printCard(arr);
        board.getCard((Letter) E, (Number) THREE)->printCard(arr);
        board.getCard((Letter) E, (Number) FOUR)->printCard(arr);
        break;
    case Side::right:
        board.getCard((Letter) B, (Number) FIVE)->printCard(arr);
        board.getCard((Letter) C, (Number) FIVE)->printCard(arr);
        board.getCard((Letter) D, (Number) FIVE)->printCard(arr);
        break;
    default:
        cout << "Invalid side" << endl;
        break;
    }

    cout << arr[0] << endl << arr[1] << endl << arr[2] << endl;
}

void Game::clearScreen(){
    cout<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

Player& Game::getNextPlayer(int n){
    current++;
    current=current%n;
    return getPlayer((Side) current);
}

void Game::resetCurrent(){
    current = 0;
}


ostream& operator<<(ostream& os, const Game& game) {
    //os << board;
    return os;
}

//Node* Node::getNextNode(){
//    return next;
//}
//
//Node* Node::getPrevNode(){
//    return prev;
//}
//
//void Node::add(Node* n){
//    this->prev = n;
//    n->next = this;
//
//    this->traverseAdd(n, this);
//}
//
//void Node::traverseAdd(Node* n, Node* start){
//    if(next!=start)
//        this->next->traverseAdd(n, start);
//    else{
//        this->next = n;
//        n->prev = this;
//    }
//}
//
//void Node::remove(){
//    this->next->prev = this->prev;
//    this->prev->next = this->next;
//
//    //this->next = nullptr;
//    //this->prev = nullptr;
//}
//
//Player& Node::getPlayer(){
//    return p;
//}
