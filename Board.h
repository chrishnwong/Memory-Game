#ifndef board_H
#define board_H

#include <iostream>
#include <string>

enum class Letter {
    A,
    B,
    C,
    D,
    E
};

enum class Number {
    1,
    2,
    3,
    4,
    5
};

class Board {
    string* _display;

    public:
        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown( const Letter&, const Number& );
        void reset();

        Board& operator << (const Board& b);
};

#endif
