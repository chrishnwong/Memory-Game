#ifndef CARD_H
#define CARD_H

#include<string>
#include<iostream>

using namespace std;

enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
enum FaceBackground {Red, Green, Purple, Blue, Yellow};

class CardDeck;

class Card {
    public:
        int getNRows() const;
        string operator()(int row);
        void printCard(string[3]);


        FaceAnimal getAnimal()const{return animal;};
        FaceBackground getBackground()const{return color;};

        //conversion operator
        operator FaceAnimal() const;
        operator FaceBackground() const;



    private:
        FaceAnimal animal;
        FaceBackground color;
        const static int nRows = 3;
        friend CardDeck;

        Card(FaceAnimal, FaceBackground);
};

#endif // CARD_H
//Written by jacqui35 and chrishnwong
//github link at https://github.com/chrishnwong/Memory-Game/
