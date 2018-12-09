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

    for (int i = 0; i < numPlayers; i++) {
        Player& player = game.getPlayer((Side) i);
        cout << "Revealing cards for " << player.getName() << ". All other players please look away" << endl << endl;
        //game.threeCardReveal(player.getSide());
        //game.clearScreen();

    }


    while (!rules.gameOver(game)) {
        //int survivors = numplayers;
        Game::board.reset();
        bool firstPlay = true;
        Letter letterForbid = Letter(2);
        Number numForbid = Number(2);

        //players are active again after the end of every round
        for (int i = 0; i < numPlayers; i++) {
        Player& player = game.getPlayer((Side) i);
        player.setActive(true);

        }


        Player* current = &game.getPlayer((Side) 0);
        game.resetCurrent();



        cout<< "starting new round..."<<endl;
        cout << endl;

        cout << "Game Display:" << endl;
        cout << Game::board;
        cout << endl;



        while (!rules.roundOver(game)) {
            cout << "Round " << game.getRound() << ":" << endl;
            cout << "It is now Player " << current->getName() << "'s turn" << endl;
            cout << endl;

            // select first card
            Letter letterInput; //= A;
            //char letterInput;
            Number numInput;
            //int numInput;

            bool resetForbidden = false;
            bool cardValid = false;
            Card* chosenCard;

            while(!cardValid){

                cout << "Enter the coordinates of the first card you want to flip on the board."<< endl;
                cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                cout << "Enter the number of your choice.";
                cin >> letterInput;
                cout << endl;

                cout << "On which Column is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                cout << "Enter the number of your choice.";
                cin >> numInput;
                cout << endl;

                if((Game::board.isFaceUp(letterInput, numInput))){
                    cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                    cout << endl;
                }else if(letterInput == letterForbid && numInput == numForbid){
                    cout << "This card is blocked.";
                    cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                    cout << endl;
                    resetForbidden = true;
                }else{
                    cardValid = true;

                }
            }

            if(resetForbidden){
                letterForbid = Letter(2);
                numForbid = Number(2);

            }
            resetForbidden = false;

            // set current card pointer
            chosenCard = game.getCard(letterInput, numInput);
            game.setCurrentCard(chosenCard);

            // turn card faceup
            if(Game::board.turnFaceUp(letterInput, numInput)){
                cout << "Card Flipped Sucessfully." <<endl;
                cout << endl;
            }else{
                cout << "Card Flipping Failed." <<endl;
                cout << endl;
            }


            // print the updated board
            cout << "Game Display:" << endl;
            cout << Game::board;
            cout << endl;



            //Expert Mode Variables
            bool isCrab = false;
            bool isTurtle = false;
            bool isWalrus = false;
            bool fromCrab = false;

            if (!firstPlay){
                if (!rules.isValid(game)){
                    cout << "You don't have a match, you lose this round!" <<endl;
                    cout << endl;

                    current->setActive(false);

                }else{
                    cout << "Congratz you have a match! You survive this turn!" <<endl;
                    cout << endl;

                    //EXPERT MODE SECTION
                    //Expert ability activated only when there is a match
                    if(gameVersion == 2){
                        bool cardValidExp = false;
                        Letter letterInputExp;
                        Number numInputExp;

                        //Crab Card
                        do{
                            if(chosenCard->getAnimal()==FaceAnimal::Crab){
                                cout << "You flipped a Crab Card! Please flip another card on the board that is not already faced up!" <<endl;
                                cout << endl;
                                while(!cardValidExp){

                                    cout << "Enter the coordinates of the card you want to face up on the board."<< endl;
                                    cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                                    cout << "Enter the number of your choice.";
                                    cin >> letterInputExp;
                                    cout << endl;

                                    cout << "On which Column is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                                    cout << "Enter the number of your choice.";
                                    cin >> numInputExp;
                                    cout << endl;

                                    if((Game::board.isFaceUp(letterInputExp, numInputExp))){
                                       cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                                       cout << endl;
                                    }else{
                                        cardValidExp = true;

                                    }
                                    // turn card facedown
                                    if(Game::board.turnFaceUp(letterInputExp, numInputExp)){
                                        cout << "Card Facing Up Sucessfully." <<endl;
                                        cout << endl;
                                    }else{
                                        cout << "Card Flipping Failed." <<endl;
                                        cout << endl;
                                    }
                                }
                                cardValidExp = false;

                                Card* chosenExpCard = game.getCard(letterInputExp, numInputExp);
                                if(chosenExpCard->getAnimal() != FaceAnimal::Crab)
                                    isCrab = false;
                                else
                                    isCrab = true;

                                game.setCurrentCard(chosenExpCard);
                                chosenCard = chosenExpCard;
                                letterInput = letterInputExp;
                                numInput = numInputExp;
                                fromCrab = true;

                                // print the updated board
                                cout << "Game Display:" << endl;
                                cout << Game::board;
                                cout << endl;
                            }
                        }while(isCrab);


                        if(rules.isValid(game)){
                            if(fromCrab){
                                cout << "Congratz you have a match! You survive this turn!" <<endl;
                                cout << endl;
                            }

                            //Penguin Card
                            if (!firstPlay){
                                if(chosenCard->getAnimal()==FaceAnimal::Penguin){
                                    cout << "You flipped a Penguin Card! Please face down a card on the board that is already faced up!" <<endl <<endl;

                                    while(!cardValidExp){

                                        cout << "Enter the coordinates of the card you want to face down on the board."<< endl;
                                        cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                                        cout << "Enter the number of your choice.";
                                        cin >> letterInputExp;
                                        cout << endl;

                                        cout << "On which Column is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                                        cout << "Enter the number of your choice.";
                                        cin >> numInputExp;
                                        cout << endl;

                                        if(!(Game::board.isFaceUp(letterInputExp, numInputExp))){
                                           cout << "Please enter coordinates of a card that is valid and not faced down." <<endl <<endl;
                                        }else{
                                            cardValidExp = true;

                                        }
                                        // turn card facedown
                                        if(Game::board.turnFaceDown(letterInputExp, numInputExp)){
                                            cout << "Card Facing Down Sucessfully." <<endl<<endl;
                                        }else{
                                            cout << "Card Flipping Failed." <<endl <<endl ;
                                        }
                                    }
                                    cardValidExp = false;

                                    // if facing down current card, current card becomes the previous card
                                    if(game.getCard(letterInputExp, numInputExp) == game.getCurrentCard()){
                                        game.setCurrentCard(game.getPreviousCard());
                                    }

                                }
                            }



                            //Turtle Card
                            if(chosenCard->getAnimal()==FaceAnimal::Turtle){
                                cout << "You flipped a Turtle Card! Next player will be skipped!" <<endl << endl;
                                isTurtle = true;
                            }



                            //Walrus Card
                            if(chosenCard->getAnimal()==FaceAnimal::Walrus){
                                cout << "You flipped a Walrus Card! Point at a card that is faced down that will be blocked for the next player!" <<endl;
                                cout << endl;
                                while(!cardValidExp){

                                        cout << "Enter the coordinates of the card you want to block on the board for the next player."<< endl;
                                        cout << "On which Row is your card: A (0), B (1), C (2), D (3), E (4)" <<endl;
                                        cout << "Enter the number of your choice.";
                                        cin >> letterInputExp;
                                        cout << endl;

                                        cout << "On which Column is your card: 1 (0), 2 (1), 3 (2), 4 (3), 5 (4)" <<endl;
                                        cout << "Enter the number of your choice.";
                                        cin >> numInputExp;
                                        cout << endl;

                                        if((Game::board.isFaceUp(letterInputExp, numInputExp))){
                                           cout << "Please enter coordinates of a card that is valid and not faced up." <<endl;
                                           cout << endl;
                                        }else{
                                            cardValidExp = true;

                                        }
                                        //store blocking coard coordinates
                                        letterForbid = letterInputExp;
                                        numForbid = numInputExp;
                                    }
                                    cardValidExp = false;

                            }



                            //Octopus Card
                            int neighborPos;
                            if(chosenCard->getAnimal()==FaceAnimal::Octopus){
                                cout << "You flipped an Octopus Card! Choose a neighbor card you want to swap with your current card!" <<endl;
                                cout << endl;
                                while(!cardValidExp){
                                    cout << "What is the position of the neighbor card?  Top (0), Left (1), Bottom (2), Right (3)" <<endl;
                                    cout << "Enter the number of your choice.";
                                    cin >> neighborPos;
                                    cout << endl;

                                    if((letterInput == Letter::A) && neighborPos == 0){
                                        cout << "You reach the top edge of the board. There is no neighbor card at the top." <<endl;
                                        cout << endl;
                                        neighborPos = 4;
                                    }
                                    if((letterInput == Letter::E) && neighborPos == 2){
                                        cout << "You reach the bottom edge of the board. There is no neighbor card at the bottom." <<endl;
                                        cout << endl;
                                        neighborPos = 4;
                                    }
                                    if((numInput == Number::ONE) && neighborPos == 1){
                                        cout << "You reach the left edge of the board. There is no neighbor card at the left." <<endl;
                                        cout << endl;
                                        neighborPos = 4;
                                    }
                                    if((numInput == Number::FIVE) && neighborPos == 3){
                                        cout << "You reach the right edge of the board. There is no neighbor card at the right." <<endl;
                                        cout << endl;
                                        neighborPos = 4;
                                    }

                                    Card* tempSwap;
                                    bool tempCardStatus, tempCardStatus2;
                                    switch (neighborPos) {
                                        case 0:
                                            tempSwap = game.getCard(Letter(letterInput-1), numInput);
                                            game.setCard(letterInput, numInput, tempSwap);
                                            game.setCard(Letter(letterInput-1), numInput, chosenCard);

                                            tempCardStatus = Game::board.isFaceUp(Letter(letterInput-1), numInput);
                                            tempCardStatus2 = Game::board.isFaceUp(letterInput, numInput);

                                            if(tempCardStatus)
                                                Game::board.turnFaceUp(letterInput, numInput);
                                            else
                                                Game::board.turnFaceDown(letterInput, numInput);

                                            if(tempCardStatus2)
                                                Game::board.turnFaceUp(Letter(letterInput-1), numInput);
                                            else
                                                Game::board.turnFaceDown(Letter(letterInput-1), numInput);

                                            cardValidExp = true;
                                            break;
                                        case 1:
                                            tempSwap = game.getCard(letterInput, Number(numInput-1));
                                            game.setCard(letterInput, numInput, tempSwap);
                                            game.setCard(letterInput, Number(numInput-1), chosenCard);

                                            tempCardStatus = Game::board.isFaceUp(letterInput, Number(numInput-1));
                                            tempCardStatus2 = Game::board.isFaceUp(letterInput, numInput);

                                            if(tempCardStatus)
                                                Game::board.turnFaceUp(letterInput, numInput);
                                            else
                                                Game::board.turnFaceDown(letterInput, numInput);

                                            if(tempCardStatus2)
                                                Game::board.turnFaceUp(letterInput, Number(numInput-1));
                                            else
                                                Game::board.turnFaceDown(letterInput, Number(numInput-1));

                                            cardValidExp = true;
                                            break;
                                        case 2:
                                            tempSwap = game.getCard(Letter(letterInput+1), numInput);
                                            game.setCard(letterInput, numInput, tempSwap);
                                            game.setCard(Letter(letterInput+1), numInput, chosenCard);

                                            tempCardStatus = Game::board.isFaceUp(Letter(letterInput+1), numInput);
                                            tempCardStatus2 = Game::board.isFaceUp(letterInput, numInput);

                                            if(tempCardStatus)
                                                Game::board.turnFaceUp(letterInput, numInput);
                                            else
                                                Game::board.turnFaceDown(letterInput, numInput);

                                            if(tempCardStatus2)
                                                Game::board.turnFaceUp(Letter(letterInput+1), numInput);
                                            else
                                                Game::board.turnFaceDown(Letter(letterInput+1), numInput);

                                            cardValidExp = true;
                                            break;
                                        case 3:
                                            tempSwap = game.getCard(letterInput, Number(numInput+1));
                                            game.setCard(letterInput, numInput, tempSwap);
                                            game.setCard(letterInput, Number(numInput+1), chosenCard);

                                            tempCardStatus = Game::board.isFaceUp(letterInput, Number(numInput+1));
                                            tempCardStatus2 = Game::board.isFaceUp(letterInput, numInput);

                                            if(tempCardStatus)
                                                Game::board.turnFaceUp(letterInput, numInput);
                                            else
                                                Game::board.turnFaceDown(letterInput, numInput);

                                            if(tempCardStatus2)
                                                Game::board.turnFaceUp(letterInput, Number(numInput+1));
                                            else
                                                Game::board.turnFaceDown(letterInput, Number(numInput+1));

                                            cardValidExp = true;
                                            break;
                                        default:
                                            cardValidExp = false;
                                            cout << "Please enter position of a card that is valid." << endl;
                                            cout << endl;
                                            break;
                                    }
                                }

                            }

                        }else{
                           if(fromCrab){
                                cout << "You don't have a match, you lose this round!" <<endl;
                                cout << endl;
                           }
                        }






                    }//expert section end
                }
                // display game
                cout << "Game Display:" << endl;
                cout << Game::board;
                cout << endl;
            }

            firstPlay = false;



            for(int i=0;i<numPlayers;i++){

                current = &game.getNextPlayer(numPlayers);

                // Turtle card skips next player
                if(isTurtle){
                    current = &game.getNextPlayer(numPlayers);
                }
                if(current->isActive()){
                    break;
                }

            }
            isTurtle = false;

        }// end of round

        game.incRound();


        Reward *reward = rewardDeck.getNext();
        current->addReward(*reward);
        cout << "Player "<< current->getName() << ", you won this round! You got " <<*reward << " rubies for this round!" <<endl;
        cout << endl;
        cout << endl;
        cout << endl;


    }// end of game


    game.getPlacements();

    return 0;


}
