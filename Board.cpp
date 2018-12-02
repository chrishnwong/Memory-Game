#include "Board.h"
#include <stdexcept>
#include <iostream>

Board::Board(){

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cRecords[i][j].cardStatus = false;
        }
    }

}


Board::~Board() {

}

Board& Board::operator=(const Board& b){
    //this->cRecords = b.cRecords;
    //deep copy

    for (int i = 0; i < 5; i++){
        for(int j = 0; i < 5; i++){
            this->cRecords[i][j].card = b.cRecords[i][j].card;
            this->cRecords[i][j].cardStatus = b.cRecords[i][j].cardStatus;
            this->cRecords[i][j].cardDisplayStr = b.cRecords[i][j].cardDisplayStr;
        }
    }

    this->expertDisplay = b.expertDisplay;
    this->expertRules = b.expertRules;

    return *this;
}

bool Board::isFaceUp(const Letter& let, const Number& num) const {
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }
    //if (cardsStatus[let][num] == true) {
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
    //if (cardsStatus[let][num] == true) {
    if (cRecords[let][num].cardStatus == true) {
        return false;
    }else{
        //cardsStatus[let][num] = true;
        cRecords[let][num].cardStatus = true;
        return true;
    }
}

bool Board::turnFaceDown(const Letter& let, const Number& num) {
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }
    //if (cardsStatus[let][num] == false) {
    if (cRecords[let][num].cardStatus == false) {
        return false;
    }else{
        //cardsStatus[let][num] = false;
        cRecords[let][num].cardStatus = false;
        return true;
    }
}

Card* Board::getCard(const Letter& let, const Number& num) {
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }
    //return cards[let][num];
    return cRecords[let][num].card;
}

void Board::setCard(const Letter& let, const Number& num, Card* c){
    if ( row < static_cast<int>(let) || column < static_cast<int>(num) ) {
        throw std::out_of_range("Letter or Number Index given is out of range.");
    }
    //bool tempStatus = cardsStatus[let][num];
    //cards[let][num] = c;
    cRecords[let][num].card = c;
}

void Board::reset() {
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            //cardsStatus[i][j] = false;
            cRecords[i][j].cardStatus = false;
        }
    }

}

void Board::toString() {
    string arr[3] = {"","",""};

    for (int i = Letter::A; i <= Letter::E; i++) {
        for (int j = Number::ONE; j <= Number::FIVE; j++) {
            getCard((Letter) i, (Number) j)->printCard(arr);
        }
        cout << arr[0] << endl << arr[1] << endl << arr[2] << endl;
        cout << endl;
        arr[3] = {"","",""};
    }


}
void Board::setExpDisp(bool disp){
    expertDisplay = disp;
}

void Board::setExpRules(bool rules){
    expertRules = rules;
}
