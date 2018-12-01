#include "CardDeck.h"

CardDeck *CardDeck::deck = 0;

CardDeck::CardDeck()
{
    items = new Card*[size];
    int k = 0;
    for (int i = FaceAnimal::Crab; i <= FaceAnimal::Walrus; i++) {
        for (int j = FaceBackground::Red; j <= FaceBackground::Yellow; j++) {
            items[k++] = new Card(static_cast<FaceAnimal>(i), static_cast<FaceBackground>(j));
        }
    }
}

CardDeck::~CardDeck() {
    for (int i = 0; i < size; i++) {
        delete items[i];
    }

    delete[] items;
    delete deck;
}

CardDeck& CardDeck::make_CardDeck() {
    if (!deck) {
        deck = new CardDeck;
    }

    return *deck;
}
