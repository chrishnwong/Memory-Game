#include "Rules.h"
#include "Game.h"
#include "Deck.h"
#include "CardDeck.h"
#include "RewardDeck.h"
#include "Board.h"
#include "Card.h"
//#include "Card.h"

//#define RULES_TEST;

#ifdef RULES_TEST
int main(){
    string getAnimalStr[4] = {"Crab", "Penguin", "Octopus", "Turtle", "Walrus"};
    string getBackgroundStr[4] = {"Red", "Green", "Purple", "Blue", "Yellow"};

    cout << "Creating game without expert rules or expert Display" << endl;
    Game game = Game(0, 1);

    Player p = ("test", Side::top)
    cout << "Creating player with name test and on top side" << endl;

    game.addPlayer(p);

    cout << "getting top player, should be test" << endl;
    cout << game.getPlayer(Side::top).getName() << endl;

    cout << "Creating cardDeck" << endl;
    Deck<Card> cardDeck = CardDeck::make_CardDeck();

    cout << "Shuffling cardDeck" << endl;
    cardDeck.shuffle();

    cout << "Setting cards" << endl;
    for (int i = Letter::A; i <= Letter::E; i++) {
        for (int j = Number::ONE; j <= Number::FIVE; j++) {
            game.setCard(Letter(i), Number(j), cardDeck.getNext());

        }
    }

    cout << "Getting card at A1" <<endl;
    cout << "The animal at A1 is enum: "<< game.getCard(Letter::A, Number::1)->getAnimal() << endl;
    cout << "The background at A1 is enum: "<< game.getCard(Letter::A, Number::1)->getBackground() << endl;

    cout << "Getting card at A2" <<endl;
    cout << "The animal at A2 is enum: " << game.getCard(Letter::A, Number::2)->getAnimal() << endl;
    cout << "The background at A2 is enum: " << game.getCard(Letter::A, Number::2)->getBackground() << endl;

    cout << "Setting A1 as current card" << endl;
    game.setCurrentCard(Letter::A, Number::1);

    cout << "Setting A2 as current card" << endl;
    game.setCurrentCard(Letter::A, Number::2);

    cout << "Getting current card, should be A2" << endl;
    cout << "The animal at A2 is enum: " << game.getCurrentCard()->getAnimal() << endl;
    cout << "The background at A2 is enum: " << game.getCurrentCard()->getBackground() << endl;

    cout << "Getting previous card, should be A1" << endl;
    cout << "The animal at A1 is enum: "<< game.getPreviousCard()->getAnimal() << endl;
    cout << "The background at A1 is enum: "<< game.getPreviousCard()->getBackground() << endl;

    cout << "Seeing if A1 and A2 are valid as matches" << endl;
    if(rules.isValid(game)){
        cout << "A1 and A2 match" <<  endl;
    }
    else{
        cout << "A1 and A2  do not match" <<  endl;
    }

    cout << "Setting top as inactive" << endl;
    game.getPlayer(Side::top).setActive(false);

    Player p = ("test2", Side::left)
    cout << "Creating player with name test2 and on left side" << endl;

    cout << "Setting left as active" << endl;
    game.getPlayer(Side::left).setActive(true);

    cout << "getting next active player from top, should be test2" << endl;
    cout << "The next active player's name is: " << rules.getNextPlayer(game).getName() << endl;

    cout <<  "Checking if game is over, game should not be over" <<  endl;

    if(rules.gameOver(game)){
        cout << "The game is not over" <<  endl;
    }
    else{
        cout << "The game is over, something is wrong" <<  endl;
    }

    cout << "Round should be over" << endl;
    if(rules.roundOver(game)){
        cout << "The Round is over" <<  endl;
    }
    else{
        cout << "The Round is not over, something is wrong" <<  endl;
    }

    cout << "This concludes the public method tests for Rules.cpp" << endl;
}
#endif

Rules::Rules(){
    // TODO Should something be here?
}

bool Rules::isValid(const Game& game){  //adding const hmmm..
    if(game.getPreviousCard()->getAnimal() == game.getCurrentCard()->getAnimal()){
        return true;
    }else if(game.getPreviousCard()->getBackground() == game.getCurrentCard()->getBackground()){
        return true;
    }else{
        return false;
    }
}

bool Rules::gameOver(const Game& game) {
    if(game.getRound() >= 7){
        return true;
    }else{
        return false;
    }
}

bool Rules::roundOver(const Game& game) {
    //bool flag = true;
    int numActivePlayers=0;

    for(int i = 0; i < game.getPlayerVector()->size(); i++){
        if((game.getPlayerVector()->at(i).isActive())){
            numActivePlayers++;
            //break;
        }
    }
    if (numActivePlayers > 1){
        return false;
    }else{
        return true;
    }

    //if(flag)
    //    cout<<"true"<<endl;
    //else
    //    cout<<"false"<<endl;
    // return flag;
}
const Player& Rules::getNextPlayer(const Game& game){
    for(int i = 0; i < game.getPlayerVector()->size(); i++){
        if((game.getPlayerVector()->at(i).isActive())){
            return game.getPlayerVector()->at(i);
        }
    }
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
