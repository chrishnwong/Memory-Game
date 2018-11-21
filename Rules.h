#ifndef RULES_H
#define RULES_H

#include "Game.h"


class Game;

class Rules {
    public:
        Rules();
        bool isValid(const Game&);
        bool gameOver(const Game&);
        bool roundOver(const Game&);
};

#endif // RULES_H
