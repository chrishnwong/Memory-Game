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

    cardDeck.shuffle();
    rewardDeck.shuffle();

    cout<<game<<endl;

    while (!rules.gameOver(game)) {
        board.reset();

        for (int i = 0; i < numPlayers; i++) {
            Player player = game.getPlayer((Side) i);
            player.setActive(true);

            cout << "Revealing cards for " << player.getName() << ". All other players please look away" << endl << endl;
            game.threeCardReveal(player.getSide());
            game.clearScreen();

        }

        Node* start;
        start->p = game.getPlayer(top);

        for(int i = 1; i < numPlayers; i++){
            Node* n;
            n->p = game.getPlayer((Side) i);
            start->add(n);
        }

        Node* current = start;

        while (!rules.roundOver(game)) {

            // select cards
            // turn card faceup
            // update board

            if (!rules.isValid(game)){
                current->getPlayer().setActive(false);
                current->remove();
            }

            // display game
            current = current->getNextNode();
        }



        for (int i = 0; i < numPlayers; i++) {
            Player player = game.getPlayer((Side) i);
            if (player.isActive()) {
                Reward *reward = rewardDeck.getNext();
                player.addReward(*reward);
            }
        }


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
