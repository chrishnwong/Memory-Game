#include "Deck.h"

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

template <class C>
int Deck<C>::getSize() const{
    return size;
}
