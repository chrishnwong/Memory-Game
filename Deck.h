#ifndef DECK_H
#define DECK_H

#include <algorithm>

using std::random_shuffle;

template <class C>

class Deck
{
    public:
        void shuffle(){random_shuffle(&items[0], &items[size-1]);};
        C* getNext(){return items[current++];};
        bool isEmpty() const{return current == size;};
        int getSize() const{return size;};

    protected:
        int size;
        int current;
        C **items;

};

#endif // DECK_H
