#ifndef DECK_H
#define DECK_H

#include <algorithm>

using std::random_shuffle;

template <class C>

class Deck
{
    public:
        void shuffle();
        C* getNext();
        bool isEmpty() const;
        int getSize() const;

    protected:
        int size;
        int current;
        C **items;

};


template <class C>
void Deck<C>::shuffle(){
    random_shuffle(&items[0], &items[size-1]);
}

template <class C>
C* Deck<C>::getNext(){
    return items[current++];
}

template <class C>
bool Deck<C>::isEmpty() const{
    return current == size;
}

#endif // DECK_H
