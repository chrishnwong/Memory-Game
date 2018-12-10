#include "RewardDeck.h"
//#define REWARDDECK_TEST

#ifdef REWARDDECK_TEST
int main(){
    cout << "creating Reward Deck" << endl;
    Deck<Reward> rewardDeck = RewardDeck::make_RewardDeck();

    cout<< "Unshuffled, the Rewards are as follows" << endl;
    for(int i =0; i<7; i++){
        cout << rewardDeck.getNext() << endl;
    }

    if(rewardDeck.isEmpty()){
        cout << "Reward deck is empty" << endl;
    }
    else{
        cout << "Reward deck is not empty, something is wrong" << endl;
    }

    rewardDeck = rewardDeck::make_RewardDeck();
    cout << "Deck created successfully" << endl;


    cout << "Shuffling, rewardDeck" << endl;
    rewardDeck.shuffle();

    cout<< "Shuffled, the Rewards are as follows" << endl;
    for(int i =0; i<7; i++){
        cout << rewardDeck.getNext() << endl;
    }

    cout << "This concludes the public method tests for RewardDeck.cpp" << endl;

}
#endif

RewardDeck *RewardDeck::rewDeck = 0;

RewardDeck::RewardDeck(){
}


RewardDeck& RewardDeck::make_RewardDeck(){

    if (rewDeck == 0){
        rewDeck = new RewardDeck();

        for (int i=0; i<3; i++){
            Reward *elePtr = new Reward(static_cast<Rubies>(1));
            rewDeck->elements.push_back(*elePtr);
        }
        for (int i=0; i<2; i++){
            Reward *elePtr1 = new Reward(static_cast<Rubies>(2));
            rewDeck->elements.push_back(*elePtr1);
        }
        Reward *elePtr2 = new Reward(static_cast<Rubies>(3));
        rewDeck->elements.push_back(*elePtr2);

        Reward *elePtr3 = new Reward(static_cast<Rubies>(4));
        rewDeck->elements.push_back(*elePtr3);
    }
    return *rewDeck;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
