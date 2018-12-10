#include <iostream>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "Player.h"

//#define GAME_TEST;

using namespace std;

#ifdef GAME_TEST
int main(){
    string getAnimalStr[4] = {"Crab", "Penguin", "Octopus", "Turtle", "Walrus"};
    string getBackgroundStr[4] = {"Red", "Green", "Purple", "Blue", "Yellow"};

    cout << "Creating game without expert rules or expert Display" << endl;
    Game game = Game(gameVersion, numPlayers);

    cout << "Printing current round, should be 0" << endl;
    if(game.getRound() == 0){
        cout << "The current round is 0" << endl;
    }
    else{
        cout << "The current round is not 0, something is wrong" << endl;
    }

    Player p = ("test", Side::top)
    cout << "Creating player with name test and on top side" << endl;

    game.addPlayer(p);

    cout << "getting top player, should be test" << endl;
    cout << game.getPlayer(Side::top).getName() << endl;

    cout << "Creating cardDeck" << endl;
    Deck<Card> cardDeck = CardDeck::make_CardDeck();

    cout << "Setting cards" << endl;
    for (int i = Letter::A; i <= Letter::E; i++) {
        for (int j = Number::ONE; j <= Number::FIVE; j++) {
            game.setCard(Letter(i), Number(j), cardDeck.getNext());

        }
    }

    cout << "Getting card at A1" <<endl;
    cout << "The animal at A1 is enum: "<< game.getCard(Letter::A, Number::1)->getAnimal() << endl;
    cout << "The background at A1 is enum: "<< game.getCard(Letter::A, Number::1)->getBackground() << endl;

    cout << "Getting card at A2" <<endl;
    cout << "The animal at A2 is enum: " << game.getCard(Letter::A, Number::2)->getAnimal() << endl;
    cout << "The background at A2 is enum: " << game.getCard(Letter::A, Number::2)->getBackground() << endl;

    cout << "Setting A1 as current card" << endl;
    game.setCurrentCard(Letter::A, Number::1);

    cout << "Setting A2 as current card" << endl;
    game.setCurrentCard(Letter::A, Number::2);

    cout << "Getting current card, should be A2" << endl;
    cout << "The animal at A2 is enum: " << game.getCurrentCard()->getAnimal() << endl;
    cout << "The background at A2 is enum: " << game.getCurrentCard()->getBackground() << endl;

    cout << "Getting previous card, should be A1" << endl;
    cout << "The animal at A1 is enum: "<< game.getPreviousCard()->getAnimal() << endl;
    cout << "The background at A1 is enum: "<< game.getPreviousCard()->getBackground() << endl;

    cout << "This concludes the public method tests for Game.cpp" << endl;
}
#endif

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
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
