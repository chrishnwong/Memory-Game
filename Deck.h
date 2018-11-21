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

#endif // DECK_H
