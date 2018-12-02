#ifndef GAME_H
#define GAME_H


#include <string>
#include <vector>
#include <algorithm>
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "Rules.h"

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
        string place[4] = {"1st", "2nd", "3rd", "4th"};
        int current;
    public:
        //Game(int _gameVersion, int numPlayers): gameVersion(_gameVersion);
        Game(int _gameVersion, int numPlayers);
        ~Game();
        int getRound() const;
        void incRound();
        void addPlayer(const Player&);
        Player& getPlayer(Side);
        const Card* getPreviousCard() const;
        const Card* getCurrentCard() const;
        void setCurrentCard(const Card*);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void setBoard(Board);
        Player& getNextPlayer(int);
        void resetCurrent();

        void setCardDeck(CardDeck*);
        //Board& getBoard() const;
        const vector<Player>* getPlayerVector() const;
        bool sortRubies(const Player&, const Player&);
        void getPlacements();

        void threeCardReveal(Side);
        void clearScreen();

        //string toString() const;
        friend ostream& operator<<(ostream&, const Game&);
};

/*struct Node{
    Player p;
    Node *next;
    Node *prev;

    public:
        Node(Player& _p): p(_p), next(nullptr), prev(nullptr){};
        Node& operator=(const Node& n);
        bool operator!=(const Node& n);
        Node* getNextNode() const;
        Node* getPrevNode() const;
        void add(Node&);
        void remove();
        void traverseAdd(Node*, Node*);
        Player* getPlayer() const;
};
*/

#endif // GAME_H
