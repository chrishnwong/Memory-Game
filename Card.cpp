#include "Card.h"

char Card::getColour() const{
    char ch;

    switch (_colour) {
        case FaceBackground::Red:
            ch = 'r'
        case FaceBackground::Green:
            ch = 'g';
        case FaceBackground::Purple:
            ch = 'p';
        case FaceBackground::Blue:
            ch = 'b';
        case FaceBackground::Yellow:
            ch = 'y';
        default:
            ch = '?';
    }

    return ch;
};

char Card::getAnimal() const{
    char ch;

    switch (_animal) {
        case FaceAnimal::Crab:
            ch = 'C'
        case FaceAnimal::Penguin:
            ch = 'P';
        case FaceAnimal::Octopus:
            ch = 'O';
        case FaceAnimal::Turtle:
            ch = 'T';
        case FaceAnimal::Walrus:
            ch = 'W';
        default:
            ch = '?';
    }

    return ch;
};

Card& Card::operator << (const Card& c){
    return *this;
}
