#include "RewardDeck.h"

RewardDeck *RewardDeck::rewDeck = 0;

RewardDeck::RewardDeck()
{
}


RewardDeck& RewardDeck::make_RewardDeck(){

    if (rewDeck == 0){
        rewDeck = new RewardDeck();
        Reward *elePtr = new Reward(static_cast<Rubies>(0));
        rewDeck->elements.push_back(*elePtr);

        for (int i=0; i<2; i++){
            Reward *elePtr1 = new Reward(static_cast<Rubies>(1));
            rewDeck->elements.push_back(*elePtr);
        }

        Reward *elePtr2 = new Reward(static_cast<Rubies>(2));
        rewDeck->elements.push_back(*elePtr);

        Reward *elePtr3 = new Reward(static_cast<Rubies>(3));
        rewDeck->elements.push_back(*elePtr);
    }
    return *rewDeck;

}
