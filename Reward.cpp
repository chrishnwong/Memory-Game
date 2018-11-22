#include "Reward.h"

//Reward::Reward()
//{
    //nRubies = rand() %4 +1;
//}

Reward::Reward(Rubies _nRubies){
        nRubies = _nRubies;//missed an underscore
}

int Reward::getNRubies() const{
    return nRubies;
}

ostream& operator<<(ostream &os, const Reward &reward) {
    os << reward.nRubies;
    return os;
}
