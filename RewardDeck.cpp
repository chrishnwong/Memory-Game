#include "RewardDeck.h"

RewardDeck *RewardDeck::rewDeck = 0;

RewardDeck::RewardDeck()
{
    items = new Reward*[size];
    //items = new Reward[size];
    int k = 0;
    for (int i = 0; i < 3; i++) {
        items[k++] = new Reward(static_cast<Rubies>(0));
    }
    for (int i=0; i<2; i++){
        items[k++] = new Reward(static_cast<Rubies>(1));
    }
    items[k++] = new Reward(static_cast<Rubies>(2));
    items[k] = new Reward(static_cast<Rubies>(3));

}

RewardDeck::~RewardDeck(){
    for(int i=0; i<size; i++){
        delete items[i];
    }

    delete[] items;
    delete rewDeck;
}

RewardDeck& RewardDeck::make_RewardDeck(){
    if(!rewDeck){
        rewDeck = new RewardDeck;
    }
    return *rewDeck;
}
