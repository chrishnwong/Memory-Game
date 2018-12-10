#ifndef GAME_H
#define GAME_H


#include <string>
#include <vector>
#include <algorithm>
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "Rules.h"

class Game {
    private:
        vector<Player> players;
        CardDeck* cards;
        int round;
        int gameVersion;
        const Card * previousCard;
        const Card * currentCard;
        string place[4] = {"1st", "2nd", "3rd", "4th"};
        int current;
    public:
        static Board board;
        Game(int _gameVersion, int numPlayers);
        ~Game();

        int getRound() const;
        void addPlayer(const Player&);
        Player& getPlayer(Side);
        const Card* getPreviousCard()const;
        const Card* getCurrentCard()const;
        void setCurrentCard(const Card*);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);


        void nextRound();

        Player& getNextPlayer();
        void resetCurrent();
        const vector<Player>* getPlayerVector() const;


        void clearScreen();

        void getPlacements();

    private:
        void resetPlayers();
        void setCardDeck(CardDeck*);
        bool sortRubies(const Player&, const Player&);

};


#endif // GAME_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
