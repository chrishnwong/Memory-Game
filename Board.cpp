#include "Board.h"
#include <stdexcept>
#include <iostream>
#include <istream>

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

bool Board::isFaceUp(const Letter& let, const Number& num)const{
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
    if (cRecords[let][num].cardStatus == true) {
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
    //if (cardsStatus[let][num] == false) {
    if (cRecords[let][num].cardStatus == false) {
        return false;
    }else{
        //cardsStatus[let][num] = false;
        cRecords[let][num].cardStatus = false;
        return true;
    }
}

// why add constant at the end
Card* Board::getCard(const Letter& let, const Number& num) const {
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

string Board::toString() {

//     string arr[3] = {"","",""};
//     for (int i = Letter::A; i <= Letter::E; i++) {
//        for (int j = Number::ONE; j <= Number::FIVE; j++) {
//            getCard((Letter) i, (Number) j)->printCard(arr);
//        }
//        cout << arr[0] << endl << arr[1] << endl << arr[2] << endl;
//        cout << endl;
//        arr[3] = {"","",""};
//    }
//}

//    int k=0;
//    for(int i=0; i<lines.size()-1; i++){
//        for(int row = 0; row <cards[i][column].getNRows(); ++row){
//            if (row == 2) {
//                lines[k] = string((char)(i+64));
//            }else{
//                lines[k] = "  ";
//            }
//            for(int j=ONE; j<=FIVE; j++){
//                lines[k] += cards[i][j](row);
//            }
//            lines[k++] += "\n";
//
//        }
//         lines[k++] += "\n\n";
//    }
//    for(int m=0; m<column; m++){
//        lines[lines.size()-1] = "   " + m;
//    }
//
//    return lines;

//    string result;
//
//    for(int i=0; i<row; i++){
//        result += (char) (i+64);
//
//        for(int j=0, j<column; j++){
//
//        }
//    }
//
        string res;
        if(!expertDisplay){
            for(int i=0; i<row; i++){
                for(int j=0; j<column; j++){
                        res += (cRecords[i][j].cardStatus? "t":"f");
                }
            }
        }
        else{
            //implement expert display
        }
        return res;
}

ostream& operator<<(ostream& os, const Board& board){
    string arr[3] = {"","",""};

    for (int i = Letter::A; i <= Letter::E; i++) {
        for (int j = Number::ONE; j <= Number::FIVE; j++) {
            if(board.isFaceUp(Letter(i), Number(j))){
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
}

//istream& operator>>(istream& is, Letter& let)
//{
//    int a;
//    is >> a;
//    let = static_cast<Letter>(a);
//
//    return is;
//}

void Board::setExpDisp(bool disp){
    expertDisplay = disp;
}

void Board::setExpRules(bool rules){
    expertRules = rules;
}

