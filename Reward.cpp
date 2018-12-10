#include "Deck.h"
#include "RewardDeck.h"
#include "Reward.h"

#ifdef REWARD_TEST
int main(){

    Deck<Reward> rewardDeck = RewardDeck::make_RewardDeck();

    cout<< "Unshuffled, the Rewards are as follows" << endl;
    for(int i =0; i<7; i++){
        Reward *reward = rewardDeck.getNext();
        cout << *reward << endl;
    }

    cout << "Assigning the last printed Rubies to an int, using conversion operator" << endl;
    int rewardT = *reward;

    cout << rewardT << endl;
    
    cout << "This concludes the public method tests for Reward.cpp" << endl;
}
#endif
//Reward::Reward()
//{
    //nRubies = rand() %4 +1;
//}

Reward::Reward(Rubies _nRubies){
        nRubies = _nRubies;
}

int Reward::getNRubies() const{
    return nRubies;
}

Reward::operator int(){
    return nRubies;

}

ostream& operator<<(ostream &os, const Reward &reward) {
    os << reward.nRubies;
    return os;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
