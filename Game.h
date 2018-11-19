#ifndef rules_H
#define rules_H

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Card.h"
#include "Board.h"

using std::vector;

class Game {
    bool _expDisplay;
    bool _expMode;
    Board _b;
    vector<Player> _p;
    int _round;


    public:
        int getRound();
        void addPlayer( const Player& p);
        Player& getPlayer(Side s);
        const Card* getCurrentCard();
        void setCurrentCard(const Card* c);
        Card* getCard(const Letter& l, const Number& n);
        void setCard(const Letter& l, const Number& n, Card* c);

        void setAllActive();
        void expModeOn();
        void expDispOn();
        void incRound();

        Game& operator << (const Game& g);
};

#endif
