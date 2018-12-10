#include "Rules.h"
//#include "Card.h"

Rules::Rules(){

}



bool Rules::isValid(const Game& game){
    //const Card* pc = game.getPreviousCard();
    if((FaceAnimal)*game.getPreviousCard() == (FaceAnimal)*game.getCurrentCard()){
        return true;
    }else if((FaceBackground)*game.getPreviousCard() == (FaceBackground)*game.getCurrentCard()){
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
