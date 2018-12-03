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

int myrandom (int i) { return std::rand()%i;}

int main() {


//    std::srand ( unsigned ( std::time(0) ) );
//
//    std::vector<int> myvector; //(5);  // 5 default-constructed ints
//    for (int i=1; i<10; ++i) myvector.push_back(i);
//    std::random_shuffle(myvector.begin(), myvector.end());
//
//  std::vector<int>::reverse_iterator rit = myvector.rbegin();
//
////  int i=0;
////  for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
////    *rit = ++i;
//
//  std::cout << "myvector contains:";
//  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//    std::cout << ' ' << *it;
//  std::cout << '\n';
//



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
        game.getBoard().reset();

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
