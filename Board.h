#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Card.h"

using namespace std;

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

CardDeck* cards;

class Board {
    private:
        int row = 5;
        int column = 5;
        //string lines[row*5+1];
        //Card* cards[row][column];
        //bool cardsStatus[row][column];

        cardRecords cRecords[5][5];

    public:
        Board();
        ~Board();

        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void reset();
        string toString();
};

#endif // BOARD_H
