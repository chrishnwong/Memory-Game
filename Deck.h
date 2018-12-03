#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <vector>

using std::random_shuffle;

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
        typename std::vector<C>::reverse_iterator riter;
        Deck(){riter = elements.rbegin();}

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

    if(riter != elements.rend()){
        return &(*riter++);
    }
//    else{
//        return nullptr;
//    }
}

template <class C>
bool Deck<C>::isEmpty() const{
    //return current == size;
    return std::vector<C>::empty();
}

#endif // DECK_H
