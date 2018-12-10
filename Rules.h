#ifndef RULES_H
#define RULES_H

#include "Game.h"


class Game;

class Rules {
    public:
        Rules();
        bool isValid(const Game&); //adding constant hmm...
        bool gameOver(const Game&);
        bool roundOver(const Game&);
        const Player& getNextPlayer(const Game&);
};

#endif // RULES_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
