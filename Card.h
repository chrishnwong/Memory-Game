#ifndef card_H
#define card_H

#include <iostream>
#include <string>

enum class FaceAnimal {
    Crab,
    Penguin,
    Octopus,
    Turtle,
    Walrus
};

enum class FaceBackground {
    Red,
    Green,
    Purple,
    Blue,
    Yellow
};

class Card {
    FaceAnimal _animal;
    FaceBackground _colour;
    public:
        Card(FaceAnimal animal, FaceBackground colour);
        char getColour() const;
        char getAnimal() const;

        Card& operator << (const Card& c);
};



#endif
