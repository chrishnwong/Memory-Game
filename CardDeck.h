#ifndef CARDDECK_H
#define CARDDECK_H

#include "Deck.h"
#include "Card.h"

class CardDeck: public Deck<Card>
{
    friend class Board;
    public:
        static CardDeck& make_CardDeck();

    private:
        static const int size = 25;
        static CardDeck *deck;
        CardDeck();


};

#endif // CARDDECK_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
