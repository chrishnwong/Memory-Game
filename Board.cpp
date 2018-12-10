#include "Board.h"
#include "CardDeck.h"
#include "Deck.h"
#include "Card.h"
#include <stdexcept>
#include <iostream>
#include <istream>

//#define BOARD_TEST;

#ifdef BOARD_TEST
int main(){
    Board b = Board();

    // Should
    if(b.turnFaceUp(Letter::A,Number::1)){
        cout << "Flip up A1 success" << endl;
    }
    else{
        cout << "Flip up A1 failure, something is wrong" << endl;
    }

    if(b.isFaceUp(Letter::A,Number::1)){
        cout << "A1 is flipped up" << endl;
    }
    else{
        cout << "A1 is flipped down, something is wrong" << endl;
    }

    if(b.turnFaceDown(Letter::A,Number::1)){
        cout << "Flip down A1 success" << endl;
    }
    else{
        cout << "Flip down A1 failure, something is wrong" << endl;
    }

    b.reset();
    cout << "All cards should be face down now" << endl;

    if(!(b.isFaceUp(Letter::A,Number::1))){
        cout << "A1 is flipped up, something is wrong" << endl;
    }
    else{
        cout << "A1 is flipped down" << endl;
    }

    Card testcard = Card(FaceAnimal::Crab, FaceBackground::Red);
    cout << "Creating a card with animal of crab and red background" << endl;

    b.setCard(Letter::A, Number::1, *newCard)
    cout << "Setting the new card to A1" << endl;

    if(b.getCard(Letter::A, Number::1)->getAnimal() == FaceAnimal::Crab){
        cout << "The animal at A1 is a crab" << endl;
    }
    else{
        cout << "The animal at A1 is not a crab, something is wrong" << endl;
    }

    cout << "This concludes the public method tests for Board.cpp" << endl;
}
#endif

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
    //if (cardsStatus[let][num] == false) {
    if (cRecords[let][num].cardStatus == false || (static_cast<int>(let)==2 && static_cast<int>(num)==2)) {
        return false;
    }else{
        //cardsStatus[let][num] = false;
        cRecords[let][num].cardStatus = false;
        return true;
    }
}

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

bool Board::getExpDisp() const{
    return expertDisplay;
}
bool Board::getExpRules() const{
    return expertRules;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
