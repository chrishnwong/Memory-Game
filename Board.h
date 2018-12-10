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
    //   A           top
    //   B     left      right
    //   .          bottom
    //   .
    //   .      1   2   .  .  .
    private:
        int row = 5;
        int column = 5;//These won't change so im gonna declare them const
        //string lines[row*5+1];
        //Card* cards[row][column];
        //bool cardsStatus[row][column];

        cardRecords cRecords[5][5];
        bool expertDisplay;
        bool expertRules;
    public:
        Board();
        ~Board();
        Board& operator=(const Board&);
        // assignment operator here


        bool isFaceUp(const Letter&, const Number&)const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);

        Card* getCard(const Letter&, const Number&) const;

        void setCard(const Letter&, const Number&, Card*);
        void reset();

        string toString();
        void setExpDisp(bool);
        void setExpRules(bool);
        friend ostream& operator<<(ostream&, const Board&);
        //friend istream& operator>>(istream&, Letter&);

    private:
        bool getExpDisp() const;
        bool getExpRules() const;
        cardRecords* getcRecords();

};


/*class zeroCards: public exception {
    virtual const char* err() const throw() {
        return "There are no more cards!";
    }
} NoMoreCards;*/

#endif // BOARD_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
