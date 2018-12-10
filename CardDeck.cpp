#include "CardDeck.h"

CardDeck *CardDeck::deck = 0;

CardDeck::CardDeck()
{
}


CardDeck& CardDeck::make_CardDeck() {

    if(deck == 0){
        deck = new CardDeck();
        for (int i = FaceAnimal::Crab; i <= FaceAnimal::Walrus; i++) {
            for (int j = FaceBackground::Red; j <= FaceBackground::Yellow; j++) {
                    Card *elePtr = new Card(static_cast<FaceAnimal> (i),static_cast<FaceBackground> (j));
                    deck->elements.push_back(*elePtr);
            }
        }
    }
    return *deck;
}
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
