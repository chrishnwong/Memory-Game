#include "Reward.h"

Reward::Reward(Rubies _nRubies){
        nRubies = _nRubies;
}

int Reward::getNRubies() const{
    return nRubies;
}

ostream& operator<<(ostream &os, const Reward &reward) {
    os << reward.nRubies;
    return os;
}

Reward::operator int(){
    return nRubies;

}


//Reward::Reward()
//{
    //nRubies = rand() %4 +1;
//}

//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
