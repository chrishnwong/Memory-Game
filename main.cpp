#include <iostream>
#include "Game.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Rules.h"

using namespace std;

int main() {
    Game game;
    int gameVersion;
    int numPlayers;

    cout << "Game version: Base (1), Expert(2)" << endl;
    cin >> gameVersion;
    cout << "Number of players: 2-4" << endl;
    cin >> numPlayers;

    game = Game(gameVersion, numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter name for player " << (i + 1) << endl;
        cin >> name;

        Player player = Player(name, (Side) i);

        game.addPlayer(player);
    }

    CardDeck cardDeck = CardDeck::make_CardDeck();
    //RewardDeck rewardDeck = RewardDeck::make_RewardDeck();
    Rules rules;
    //Board board2 = game.board;
    //cout << board2.toString();
    //Board board;

    //shuffles
    //display game

    while (!rules.gameOver(game)) {
        // set cards to facedown


//        for (int i = 0; i < numPlayers; i++) {
//            Player player = game.getPlayer();
//            player.setActive(true);
//        }
//
//        for (int i = 0; i < numPlayers; i++) {
//            Player player = game.getPlayer();
//            // temporarily reveal 3 cards directly in front of player
//        }
//
//        while (!rules.roundOver(game)) {
//            Player player = game.getPlayer();
//
//            // turn card faceup
//            // update board
//
//            if (!rules.isValid(game)) {
//                player.setActive(false);
//            }
//
//            // display game
//        }
//
//        for (int i = 0; i < numPlayers; i++) {
//            Player player = game.getPlayer();
//            if (player.isActive()) {
//                // Reward *reward = rewardDeck.getNext();
//                // player.addReward(*reward);
//            }
//        }
//
//        // update board
//    }


    string result;
    for(int i=0; i<5; i++){
        result += (char) (i+65);
    }
    cout << result;

    return 0;
}
}
