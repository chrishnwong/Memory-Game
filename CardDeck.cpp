#include "CardDeck.h"
#include "Deck.h"

CardDeck *CardDeck::deck = 0;

//#define CARDDECK_TEST

#ifdef CARDDECK_TEST
int main(){
    string getAnimalStr[4] = {"Crab", "Penguin", "Octopus", "Turtle", "Walrus"};
    string getBackgroundStr[4] = {"Red", "Green", "Purple", "Blue", "Yellow"};

    Deck<Card> cardDeck = CardDeck::make_CardDeck();
    cout << "Deck created successfully" << endl;

    cout << "In order, the animals in the deck created are: " << endl;
    for(int i =0;i < 25;i++){
        cout << getAnimalStr[static_cast<int> (cardDeck.getNext()->getAnimal())] << endl;
    }

    if(cardDeck.isEmpty()){
        cout << "Card deck is empty" << endl;
    }
    else{
        cout << "Card deck is not empty, something is wrong" << endl;
    }
    
    cardDeck = CardDeck::make_CardDeck();
    cout << "Deck created successfully" << endl;

    cout << "In order, the colours in the deck created are: " << endl;
    for(int i =0;i < 25;i++){
        cout << getBackgroundStr[static_cast<int> (cardDeck.getNext()->getBackground())] << endl;
    }

    cardDeck.shuffle();

    cout << "Now shuffled, the animals in the deck created are: " << endl;
    for(int i =0;i < 25;i++){
        cout << getAnimalStr[static_cast<int> (cardDeck.getNext()->getAnimal())] << endl;
    }

    cout << "This concludes the public method tests for CardDeck.cpp" << endl;
    return 0;
}
#endif

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
