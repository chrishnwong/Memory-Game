#include <iostream>
#include "Game.h"
#include "Deck.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Rules.h"
#include "Board.h"
#include "Card.h"
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>
#include <list>

using namespace std;

//Initialize the board
Board Game::board = Board();



istream& operator>>(istream& is, Letter& let)
{
    int a;
    is >> a;
    let = static_cast<Letter>(a);

    return is;
}

istream& operator>>(istream& is, Number& num)
{
    int a;
    is >> a;
    num = static_cast<Number>(a);

    return is;
}



int myrandom (int i) { return std::rand()%i;}

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

    Deck<Card> cardDeck = CardDeck::make_CardDeck();
    Deck<Reward> rewardDeck = RewardDeck::make_RewardDeck();
    cardDeck.shuffle();
    rewardDeck.shuffle();
    Rules rules = Rules();
    Game game = Game(gameVersion, numPlayers);

    // set the board
    for (int i = Letter::A; i <= Letter::E; i++) {
        for (int j = Number::ONE; j <= Number::FIVE; j++) {
            game.setCard(Letter(i), Number(j), cardDeck.getNext());

        }
    }

    if (cardDeck.isEmpty()){
        cout << "EMPTY" <<endl;
    }else{
        cout << "NOT EMPTY" <<endl;
    }



    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter name for player " << (i + 1) << endl;
        cin >> name;

        Player player = Player(name, (Side) i);

        game.addPlayer(player);
    }

    cout << endl;

    cout << "Game Display:" << endl;
    cout << Game::board;


    cout<<game<<endl;

    while (!rules.gameOver(game)) {
        Game::board.reset();

        for (int i = 0; i < numPlayers; i++) {
            Player& player = game.getPlayer((Side) i);
            player.setActive(true);

            cout << "Revealing cards for " << player.getName() << ". All other players please look away" << endl << endl;
            //game.threeCardReveal(player.getSide());
            //game.clearScreen();

        }

//        Node* start;
//        start->p = game.getPlayer(top);
//
//        for(int i = 1; i < numPlayers; i++){
//            Node* n;
//            n->p = game.getPlayer((Side) i);
//            start->add(n);
//        }
//
//        Node* current = start;

        Player* current = &game.getPlayer((Side) 0);
        game.resetCurrent();
        cout<< "starting round"<<endl;


        while (!rules.roundOver(game)) {
            cout << "Round " << game.getRound() << ":" << endl;
            cout << "It is now Player " << current->getName() << "'s turn" << endl;

            // select first card
            Letter letterInput; //= A;
            //char letterInput;
            Number numInput;
            //int numInput;
            bool cardValid = false;
            Card* chosenCard;

            while(!cardValid){

                cout << "Enter the coordinates of the first card you want to flip on the board."<< endl;
                cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                cout << "Enter the number of your choice.";
                //cout << "Row Letter: (EX: A)" <<endl;
                cin >> letterInput;

                cout << "On which Collumn is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                cout << "Enter the number of your choice.";
                //cout<< "Collumn Number: (EX: 3)" <<endl;
                cin >> numInput;

                if((Game::board.isFaceUp(letterInput, numInput))){
                   cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                }else{
                    cardValid = true;

                }
            }

            // set current card pointer
            chosenCard = game.getCard(letterInput, numInput);
            game.setCurrentCard(chosenCard);

            // turn card faceup
            if(Game::board.turnFaceUp(letterInput, numInput)){
                cout << "Card Flipped Sucessfully." <<endl;
            }else{
                cout << "Card Flipping Failed." <<endl;
            }


            // update board
            // print the board
            if((Game::board.isFaceUp(letterInput, numInput))){
                cout << "Now its flipped" <<endl;
            }else{
                cout << "It's still not flipped" <<endl;

            }
            cout << "Game Display:" << endl;
            cout << Game::board;


            //////////////////////////second card/////////////////////////
            // select second card
            Letter letterInput2;
            //char letterInput;
            Number numInput2;
            //int numInput;
            cardValid = false;

            while(!cardValid){

                cout << "Enter the coordinates of the second card you want to flip on the board."<< endl;
                cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                cout << "Enter the number of your choice.";
                //cout << "Row Letter: (EX: A)" <<endl;
                cin >> letterInput2;

                cout << "On which Collumn is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                cout << "Enter the number of your choice.";
                //cout<< "Collumn Number: (EX: 3)" <<endl;
                cin >> numInput2;

                if((Game::board.isFaceUp(letterInput2, numInput2))){
                   cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                }else{
                    cardValid = true;

                }
            }

            // set current card pointer
            chosenCard = game.getCard(letterInput2, numInput2);
            game.setCurrentCard(chosenCard);

            // turn card faceup
            if(Game::board.turnFaceUp(letterInput2, numInput2)){
                cout << "Card Flipped Sucessfully." <<endl;
            }else{
                cout << "Card Flipping Failed." <<endl;
            }


            // update board
            // print the board
            if((Game::board.isFaceUp(letterInput2, numInput2))){
                cout << "Now its flipped" <<endl;
            }else{
                cout << "It's still not flipped" <<endl;

            }
            cout << "Game Display:" << endl;
            cout << Game::board;




            if (!rules.isValid(game)){
                cout << "You don't have a match, you lose this round!" <<endl;
                cout << "Board is resetting." <<endl;
                Game::board.turnFaceDown(letterInput, numInput);
                Game::board.turnFaceDown(letterInput2, numInput2);
                current->setActive(false);
            }else{
                cout << "Congratz you have a match! You survive this round!" <<endl;
            }

            cout << "Game Display:" << endl;
            cout << Game::board;




            // display game
            for(int i=0;i<numPlayers;i++){
                current = &game.getNextPlayer(numPlayers);
                if(current->isActive()){
                    break;
                }
            }
        }
        game.incRound();



//        for (int i = 0; i < numPlayers; i++) {
//            Player player = game.getPlayer((Side) i);
//            if (player.isActive()) {
//                Reward *reward = rewardDeck.getNext();
//                player.addReward(*reward);
//            }
//        }


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
