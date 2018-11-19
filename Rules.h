#ifndef rules_H
#define rules_H

#include <iostream>
#include <string>

#include "Game.h"

class Rules {

    public:
        bool isValid(const Game& g);
        bool gameOver(const Game& g);
        bool roundOver(const Game& g);
        const Player& getNextPlayer(const Game& g);
};

#endif
