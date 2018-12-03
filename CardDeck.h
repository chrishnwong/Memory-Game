#ifndef CARDDECK_H
#define CARDDECK_H

#include "Deck.h"
#include "Card.h"

class CardDeck: public Deck<Card>
{
    public:
        static CardDeck& make_CardDeck();

        CardDeck();
        //~CardDeck();


    private:
        static const int size = 25;
        static CardDeck *deck;
        //CardDeck();
        //~CardDeck();

};

#endif // CARDDECK_H
