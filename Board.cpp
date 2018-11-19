#include "Board.h"


Board& Board::operator << (const Board& b){
    os << _display << endl << endl; // Placeholder

    return *this;
}
