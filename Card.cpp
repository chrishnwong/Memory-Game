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
            break;
        case FaceBackground::Green:
            colorChar = "g";
            break;
        case FaceBackground::Purple:
            colorChar = "p";
            break;
        case FaceBackground::Blue:
            colorChar = "b";
            break;
        case FaceBackground::Yellow:
            colorChar = "y";
            break;
        default:
            colorChar = " ";
            break;
    }

    switch (this->animal) {
        case FaceAnimal::Crab:
            animalChar = "C";
            break;
        case FaceAnimal::Penguin:
            animalChar = "P";
            break;
        case FaceAnimal::Octopus:
            animalChar = "O";
            break;
        case FaceAnimal::Turtle:
            animalChar = "T";
            break;
        case FaceAnimal::Walrus:
            animalChar = "W";
            break;
        default:
            animalChar = " ";
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

//    //to be removed
//    if (getBackground() == 0){
//        cout << "bcg null" <<endl;
//    }else{
//        cout << "bcg not null" <<endl;
//    }

    switch (getBackground()) {
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

    //to be removed
//    if (getAnimal() == 0){
//        cout << "animal null" <<endl;
//    }else{
//        cout << "animal not null" <<endl;
//    }

    switch (getAnimal()) {
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
        return " " + string(1, colorChar) + string(1, animalChar) + string(1, colorChar);
    }else{
        return " " + string(3, colorChar);
    }

}

// card cannot be copied or assigned
// cannot add more public method
//Card& Card::operator=(Card& c){
//    this->animal = c.animal;
//    this->color = c.color;
//
//    return *this;
//}
