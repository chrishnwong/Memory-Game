#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Card.h"

using namespace std;//I'm a little uncomfortable with using namespace std, i'd rather be in control of what is and isn't belonging to std

enum Letter {
    A,
    B,
    C,
    D,
    E
};

enum Number {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};

struct cardRecords{
    Card* card;
    bool cardStatus;
    string cardDisplayStr;
};

//CardDeck* cards;
//Removed this to see if the code would work, for reasons unknown it works when this is removed

class Board {
    private:
        int row = 5;
        int column = 5;//These won't change so im gonna declare them const
        //string lines[row*5+1];
        //Card* cards[row][column];
        //bool cardsStatus[row][column];

        cardRecords cRecords[5][5];

    public:
        Board();
        ~Board();
        Board& operator=(const Board&);
        // assignment operator here


        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void reset();
        string toString();
    private:
        cardRecords* getcRecords();

};

#endif // BOARD_H
