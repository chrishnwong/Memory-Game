#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>
#include "Card.h"
#include <iterator>

using namespace std;
using std::random_shuffle;

//template <typename T>
//Iter<typename std::vector<C>::


template <class C>

class Deck
{


    public:
        void shuffle();
        C* getNext();
        bool isEmpty() const;
        int getSize() const;

    protected:
        C **items;
        std::vector<C> elements;
        int counter =0;

};


template <class C>
void Deck<C>::shuffle(){

    if(!elements.empty())
        random_shuffle(elements.begin(), elements.end());
}

template <class C>
C* Deck<C>::getNext(){

    if(counter < 25){
        auto it = elements.begin();
        auto nx = std::next(it, counter);

        if(counter == 0){
            counter++;
            return &(*it);
        }else{
            counter++;
            return &(*nx);
        }
    }else{
        return nullptr;
    }

}

template <class C>
bool Deck<C>::isEmpty() const{
    return elements.empty();
}

#endif // DECK_H
