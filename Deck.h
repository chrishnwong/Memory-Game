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
        //C **items;

    protected:
        int size;
        int current;
        C **items;
        //C *items;
        std::vector<C> elements;

        int counter =0;
        //typename std::vector<C>::iterator it = elements.begin();
        //auto it;
        //typedef typename std::vector<C>::reverse_iterator riter;

        //Iter it;
        //Deck(){//riter = elements.rbegin();
                //it = elements.begin();}

};


template <class C>
void Deck<C>::shuffle(){
    //random_shuffle(items, items+size);
    //random_shuffle(&items[0], &items[size-1]);

    if(!elements.empty())
        random_shuffle(elements.begin(), elements.end());
}

template <class C>
C* Deck<C>::getNext(){
    //return items[current++];

//    if(riter != elements.rend()){
//        //return &(*riter++);
//        return *riter++;
//    }
//    else{
//        return nullptr;
//    }

    if(counter < 25){
        auto it = elements.begin();
        auto nx = std::next(it, counter);
        //Card c = *it;

//        Card c = *nx;
//    //
//        for(int r=0; r<3; ++r){
//            string rowString = c(r);
//            cout << rowString << endl;
//        }
//        cout << "test printing" <<endl;
        //return *it++;
        if(counter == 0){
            counter++;
            return &(*it);
        }else{
            counter++;
            return &(*nx);
        }
    }else{
        cout << "no more cards to add" <<endl;
    }



//    if(it < elements.end()-1){
//        return *it++;
//    }
}

template <class C>
bool Deck<C>::isEmpty() const{
    //return current == size;
    return elements.empty();
}

#endif // DECK_H
