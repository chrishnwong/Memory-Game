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

void Card::printCard(string* arr){
    string colorChar, animalChar;



    switch (this->color) {
        case FaceBackground::Red:
            colorChar = "r";
            cout << color << endl;
            break;
        case FaceBackground::Green:
            colorChar = "g";
            cout << color << endl;
            break;
        case FaceBackground::Purple:
            colorChar = "p";
            cout << color << endl;
            break;
        case FaceBackground::Blue:
            colorChar = "b";
            cout << color << endl;
            break;
        case FaceBackground::Yellow:
            colorChar = "y";
            cout << color << endl;
            break;
        default:
            colorChar = "!";
            cout << color << endl;
            break;
    }

    switch (this->animal) {
        case FaceAnimal::Crab:
            animalChar = "C";
            cout << animal << endl;
            break;
        case FaceAnimal::Penguin:
            animalChar = "P";
            cout << animal << endl;
            break;
        case FaceAnimal::Octopus:
            animalChar = "O";
            cout << animal << endl;
            break;
        case FaceAnimal::Turtle:
            animalChar = "T";
            cout << animal << endl;
            break;
        case FaceAnimal::Walrus:
            animalChar = "W";
            cout << animal << endl;
            break;
        default:
            animalChar = "?";
            cout << animal << endl;
            break;
    }

    for(int i = 0; i < 3; i++){
        if(i != 1)
            arr[i] += colorChar + colorChar + colorChar + " ";
        else
            arr[i] += colorChar + animalChar + colorChar + " ";
    }
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

Card& Card::operator=(const Card& c){
    this->animal = c.animal;
    this->color = c.color;

    return *this;
}
