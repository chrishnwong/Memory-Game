#include "Rules.h"
//#include "Card.h"

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
