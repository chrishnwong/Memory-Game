#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "Deck.h"
#include "Reward.h"


class RewardDeck: public Deck<Reward>
{
    friend class Board;
    public:
        //virtual ~RewardDeck(){}
        static RewardDeck& make_RewardDeck();

    private:
        RewardDeck();
        //~RewardDeck();
        static const int size = 7;
        static RewardDeck *rewDeck;
        RewardDeck();
        ~RewardDeck();
};

#endif // REWARDDECK_H
