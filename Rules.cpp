#include "Rules.h"

Rules::Rules(){
    // TODO Should something be here?
}

bool Rules::isValid(const Game& game) {
    if(game.getPreviousCard() == game.getCurrentCard()){
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
    return true;
}
