#include <iostream>
#include "Game.h"
#include "Deck.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Rules.h"

using namespace std;

int main() {
    int gameVersion;
    int numPlayers;
    int gameDisplay;

    cout << "Game version: Base (1), Expert mode(2)" << endl;
    cin >> gameVersion;
    cout << "Expert display mode: Off (0), On (1)" << endl;
    cin >> gameDisplay;
    cout << "Number of players: 2-4" << endl;
    cin >> numPlayers;

    Game game = Game(gameVersion, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter name for player " << (i + 1) << endl;
        cin >> name;

        Player player = Player(name, (Side) i);

        game.addPlayer(player);
    }

    Deck<Card> cardDeck = CardDeck::make_CardDeck();
    Deck<Reward> rewardDeck = RewardDeck::make_RewardDeck();
    Rules rules = Rules();


    //cout << board2.toString();
    Board board = Board();

    //cardDeck.shuffle();
    //rewardDeck.shuffle();

    cout << game << endl;


    while (!rules.gameOver(game)) {
        board.reset();


        for (int i = 0; i < numPlayers; i++) {
            Player& player = game.getPlayer((Side) i);
            player.setActive(true);

            cout << "Revealing cards for " << player.getName() << ". All other players please look away" << endl << endl;
            //game.threeCardReveal(player.getSide());
            //game.clearScreen();
            //string asdf;
            //cin >> asdf;
        }


        //Node start = Node(game.getPlayer(top));


        /*for(int i = 1; i < numPlayers; i++){
            Node n = Node(game.getPlayer((Side) i));
            start.add(n);
            cout << "Round 2";
        }*/

        //Node current = start;

        Player* current = &game.getPlayer((Side) 0);
        game.resetCurrent();
        cout<< "starting round"<<endl;

        while (!rules.roundOver(game)) {
            cout << "Round " << game.getRound() << ":" << endl;
            cout << "It is now Player " << current->getName() << "'s turn" << endl;
            //string test;
            //cin >> test;
            // select cards
            // turn card faceup
            // update board

            //if (!rules.isValid(game)){
                current->setActive(false);
            //}

            // display game
            for(int i=0;i<numPlayers;i++){
                current = &game.getNextPlayer(numPlayers);
                if(current->isActive()){
                    break;
                }
            }

        }
        game.incRound();


/*
        for (int i = 0; i < numPlayers; i++) {
            Player player = game.getPlayer((Side) i);
            if (player.isActive()) {
                //Reward *reward = rewardDeck.getNext();
                player.addReward(*reward);
            }
        }*/


            // update board
    }


    string result;
    for(int i=0; i<5; i++){
        result += (char) (i+65);
    }
    cout << result;

    game.getPlacements();

    return 0;
}
