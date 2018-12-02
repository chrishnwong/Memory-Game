#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(FaceAnimal _animal, FaceBackground _color){
        animal = _animal;
        color = _color;
}

int Card::getNRows() const{
    return nRows;
}

string Card::operator()(int row) {
    char colorChar;
    switch (color) {
        case 0:
            colorChar = 'r';
            break;
        case 1:
            colorChar = 'g';
            break;
        case 2:
            colorChar = 'p';
            break;
        case 3:
            colorChar = 'b';
            break;
        case 4:
            colorChar = 'y';
            break;
        default:
            break;
    }

    char animalChar;
    switch (animal) {
        case 0:
            animalChar = 'C';
            break;
        case 1:
            animalChar = 'P';
            break;
        case 2:
            animalChar = 'O';
            break;
        case 3:
            animalChar = 'T';
            break;
        case 4:
            animalChar = 'W';
            break;
        default:
            break;
    }

    if (row == 1){
        char middleOfCard[3] = {colorChar, animalChar, colorChar};
        return " " + string(middleOfCard);
    }else{
        return " " + string(3, colorChar);
    }

}
