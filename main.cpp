#include "Board.h"
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"
#include "Reward.h"

using std::cin;

int main(){
    cout << "Welcome to the memory game!" << endl << endl;

    cout << "What game version would you like?" << endl;
    cout << "1)  Plain Vanilla" << endl;
    cout << "2)  Expert Mode" << endl;
    cout << "3)  Expert Display" << endl;
    cout << "4)  Both Expert Mode and Expert Display" << endl << endl;

    auto mode = -1;
    while ( select<1 || select>4 ) {
        cout << "Enter 1, 2, 3 or 4: ";
        cin >> select;
        cout << endl;
    }

    cout << "How many players would you like?" << endl << endl;

    auto players = -1;
    while ( select<2 || select>4 ) {
        cout << "Please choose between 2-4 players: " << endl;
        cin >> players;
        cout << endl;
    }

    Game g;//TODO fixup proper constructor
    Rules r;
    Board b;
    //TODO figure out how to initialize deck

    switch( mode ) {
    case 1:
        break;
    case 2:
        g.expModeOn();
        break;
    case 3:
        g.expDispOn();
        break;
    case 4:
        g.expModeOn();
        g.expDispOn();
        break;
    default:
        break;
    }

    auto name;
    for(int i=0;i<players;i++){
        cout << "Please enter the name of Player " << (i+1) << ": " << endl;
        cin >> name;

        Player p(name, i);

        g.addPlayer(&p);//TODO possible error?
    }



    cout << g << endl;

    while (!r.gameOver(g)){
        b.reset();
        g.setAllActive();

        for each player
            Temporarily reveal 3 cards directly in front of the player

        while(!r.roundOver(g)){
            #next active player takes a turn
            get selection of card to turn face up from active player
            update board in game
            if r.isValid(card){
                # player is no longer part of the current round
                current player becomes inactive
            }
            cout << g << endl;
        }
        Remaining active player receives reward (rubies)
        g.incRound();
    }

    print players with their number of rubies sorted from least to most rubies

    cout << "The winner is Player!" << endl;
}
