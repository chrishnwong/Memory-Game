#include "CardDeck.h"

CardDeck *CardDeck::deck = 0;

CardDeck::CardDeck()
{
    //items = new Card*[size];
//    items = new Card*[size];
//    int k = 0;
//    for (int i = FaceAnimal::Crab; i <= FaceAnimal::Walrus; i++) {
//        for (int j = FaceBackground::Red; j <= FaceBackground::Yellow; j++) {
//            items[k++] = new Card(static_cast<FaceAnimal>(i), static_cast<FaceBackground>(j));
//        }
//    }
    if(deck == 0){
        deck = new CardDeck();
        for (int i = FaceAnimal::Crab; i <= FaceAnimal::Walrus; i++) {
            for (int j = FaceBackground::Red; j <= FaceBackground::Yellow; j++) {
                    Card *elePtr = new Card(static_cast<FaceAnimal> (i),static_cast<FaceBackground> (j));
                    deck->elements.push_back(*elePtr);
            }
        }
    }
}

//CardDeck::~CardDeck() {
//    for (int i = 0; i < size; i++) {
//        delete items[i];
//    }
//
//    delete[] items;
//    delete deck;
//}

CardDeck& CardDeck::make_CardDeck() {
//    if (!deck) {
//        deck = new CardDeck;
//    }
//
//    return *deck;

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
