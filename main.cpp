#include <iostream>
#include "Game.h"
#include "Deck.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Rules.h"
#include "Board.h"

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

//    int k=0;
//    for(int i=0; i<5; i++){
//        for(int j=0; j<5; j++){
//            for(int r = 0; r<3; ++r){
//              Card *card = cardDeck.items[k++];
//              string rowString = &card(r);
//              cout << rowString <<endl;
//            }
//
//        }
//    }


    //cout << board2.toString();
    //Board board = Board();

    //cardDeck.shuffle();
    //rewardDeck.shuffle();

    cout << game << endl;


    while (!rules.gameOver(game)) {
        game.getBoard().reset();


        for (int i = 0; i < numPlayers; i++) {
            Player& player = game.getPlayer((Side) i);
            player.setActive(true);

            cout << "Revealing cards for " << player.getName() << ". All other players please look away" << endl << endl;
            //game.threeCardReveal(player.getSide());
            //game.clearScreen();
        }

        Player* current = &game.getPlayer((Side) 0);
        game.resetCurrent();
        cout<< "starting round"<<endl;


        while (!rules.roundOver(game)) {
            cout << "Round " << game.getRound() << ":" << endl;
            cout << "It is now Player " << current->getName() << "'s turn" << endl;

            // select first card
            Letter letterInput = A;
            //char letterInput;
            Number numInput=ONE;
            //int numInput;
            bool cardValid = false;

            //while(!cardValid){

                cout << "Enter the coordinates of the first card you want to flip on the board."<< endl;
                cout << "Row Letter: (EX: A)" <<endl;
                //cin >> letterInput;
                cout<< "Collumn Number: (EX: 3)" <<endl;
                //cin >> numberInput;

                if(!(game.getBoard().isFaceUp(letterInput, numInput))){
                   cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                }else{
                    cardValid = true;
                }

            // set current card pointer
            Card* chosenFirstCard = game.getCard(letterInput, numInput);
            game.setCurrentCard(chosenFirstCard);
          
            // turn card faceup
            if(game.getBoard().turnFaceUp(letterInput, numInput)){
                cout << "Card Flipped Sucessfully." <<endl;
            }else{
                cout << "Card Flipping Failed." <<endl;
            }

            // update board
            // print the board

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

            game.incRound();
        }


/*
        for (int i = 0; i < numPlayers; i++) {
            Player player = game.getPlayer((Side) i);
            if (player.isActive()) {
                //Reward *reward = rewardDeck.getNext();
                player.addReward(*reward);
            }
        }*/


            // update board
        //}

    }

    string result;
    for(int i=0; i<5; i++){
        result += (char) (i+65);
    }
    cout << result;

    game.getPlacements();

    return 0;


}
