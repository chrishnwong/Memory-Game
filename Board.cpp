#include "Board.h"
#include "CardDeck.h"
#include "Deck.h"
#include "Card.h"
#include <stdexcept>
#include <iostream>
#include <istream>

Board::Board(){


        //try {
        //if(crecords is empty)
            //throw NoMoreCards;
            //Deck<Card> cd = CardDeck();
            //cd.shuffle();
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(i!=2 && j!=2){
                    cRecords[i][j].cardStatus = false;
                    //cRecords[i][j].card = cd.getNext();
                }
            }
        }
    //}
    //catch (exception& e) {
        //cout << e.err() << endl;
    //}


}


Board::~Board() {

}

Board& Board::operator=(const Board& b){


    for (int i = 0; i < 5; i++){
        for(int j = 0; i < 5; i++){
            this->cRecords[i][j].card = b.cRecords[i][j].card;
            this->cRecords[i][j].cardStatus = b.cRecords[i][j].cardStatus;
        }
    }

    this->expertDisplay = b.expertDisplay;
    this->expertRules = b.expertRules;

    return *this;
}

bool Board::isFaceUp(const Letter& let, const Number& num)const{
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }

    if (cRecords[let][num].cardStatus == true) {
        return true;
    }else{
        return false;
    }
}

bool Board::turnFaceUp(const Letter& let, const Number& num) {
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }
    if (cRecords[let][num].cardStatus == true || (static_cast<int>(let)==2 && static_cast<int>(num)==2)) {
        return false;
    }else{
        cRecords[let][num].cardStatus = true;
        return true;
    }
}

bool Board::turnFaceDown(const Letter& let, const Number& num) {
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }

    if (cRecords[let][num].cardStatus == false || (static_cast<int>(let)==2 && static_cast<int>(num)==2)) {
        return false;
    }else{

        cRecords[let][num].cardStatus = false;
        return true;
    }
}

Card* Board::getCard(const Letter& let, const Number& num) const {

    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }

    return cRecords[let][num].card;
}

void Board::setCard(const Letter& let, const Number& num, Card* c){
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }

    cRecords[let][num].card = c;
}

void Board::reset() {
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cRecords[i][j].cardStatus = false;
        }
    }

}


ostream& operator<<(ostream& os, const Board& board){
    string arr[3] = {"","",""};
    string letterName[5] = {"A", "B", "C", "D", "E"};
    string numberName[5] = {"1", "2", "3", "4", "5"};
    string coord = "";

    if(!board.getExpDisp()){
        for (int i = Letter::A; i <= Letter::E; i++) {
            arr[0] = "  ";
            arr[1] = letterName[i] + " ";
            arr[2] = "  ";
            for (int j = Number::ONE; j <= Number::FIVE; j++) {
                if(i==2&&j==2){
                    for(int i = 0; i < 3; i++)
                        arr[i] += "    ";
                }else if(board.isFaceUp((Letter) i, (Number) j)){
                    board.getCard((Letter) i, (Number) j)->printCard(arr);
                }else{
                    for(int i = 0; i < 3; i++){
                        arr[i] += "zzz ";
                    }
                }
            }
            os << arr[0] << endl << arr[1] << endl << arr[2] << endl << endl;
            arr[0] = "";
            arr[1] = "";
            arr[2] = "";
        }
        os << "   1   2   3   4   5   \n";
    }
    else{

        for (int i = Letter::A; i <= Letter::E; i++) {
            for (int j = Number::ONE; j <= Number::FIVE; j++) {
                if(board.isFaceUp((Letter) i, (Number) j)){
                    board.getCard((Letter) i, (Number) j)->printCard(arr);
                    coord += letterName[i] + numberName[j] + "  ";
                }
            }
        }
        arr[2] += "\n\n" + coord;
        os << arr[0] << endl << arr[1] << endl << arr[2] << endl << endl;

    }
}



void Board::setExpDisp(bool disp){
    expertDisplay = disp;
}

void Board::setExpRules(bool rules){
    expertRules = rules;
}

bool Board::getExpDisp() const{
    return expertDisplay;
}
bool Board::getExpRules() const{
    return expertRules;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
