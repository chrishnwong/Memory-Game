#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "Deck.h"
#include "Reward.h"


class RewardDeck: public Deck<Reward>
{
    friend class Board;
    public:
        static RewardDeck& make_RewardDeck();

    private:
        static const int size = 7;
        static RewardDeck *rewDeck;
        RewardDeck();
        ~RewardDeck();
};

#endif // REWARDDECK_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
