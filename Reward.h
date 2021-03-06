#ifndef REWARD_H
#define REWARD_H

#include <iostream>

using namespace std;

class RewardDeck;

enum Rubies{
    one=1,
    two,
    three,
    four
};


class Reward
{
    friend RewardDeck;

    public:
        int getNRubies() const;
        friend ostream& operator<<(ostream&, const Reward&);
        operator int();
    private:
        Rubies nRubies;
        Reward(Rubies);
};

#endif // REWARD_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
