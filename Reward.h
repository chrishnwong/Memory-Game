#ifndef reward_H
#define reward_H

#include <iostream>
#include <string>


class Reward {
    friend class RewardDeck;
    int _nRubies;
    public:
        Reward& operator << (const Reward& r);
        operator int();
    private:
        Reward();
};



#endif
