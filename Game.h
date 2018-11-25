#ifndef GAME_H
#define GAME_H


#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "Rules.h"

using std::string;

//class Board;

class Game {
    private:
        //friend Board;
        Board board;
        vector<Player> players;
        CardDeck* cards;
        int round;
        int gameVersion;
        const Card * previousCard;
        const Card * currentCard;

    public:
        //Game(int _gameVersion, int numPlayers): gameVersion(_gameVersion);
        Game(int _gameVersion, int numPlayers);
        ~Game();
        int getRound() const;
        void addPlayer(const Player&);
        Player& getPlayer(Side);
        const Card* getPreviousCard() const;
        const Card* getCurrentCard() const;
        void setCurrentCard(const Card*);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void setBoard(Board);

        void setCardDeck(CardDeck*);
        Board& getBoard();
        vector<Player>& getPlayerVector();


        //string toString() const;
        friend ostream& operator<<(ostream&, const Game&);
};

#endif // GAME_H
