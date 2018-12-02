#ifndef REWARD_H
#define REWARD_H

#include <iostream>

using namespace std;

class RewardDeck;

enum Rubies{
    one,
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

    private:
        Rubies nRubies;
        Reward(Rubies);
};

#endif // REWARD_H
