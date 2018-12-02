#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Reward.h"

enum Side {top, left, bottom, right};


class Player
{
    private:
        string name;
        int nRubies;
        bool active;
        bool endOfGame;
        Side side;
        string getEnumSides[4] {"top", "left", "bottom", "right"};

    public:
        Player();
        Player(string _name, Side _side): name(_name), side(_side){
            active = false;
            endOfGame = false;
            nRubies = 0;
        }

        string getName() const;
        void setActive(bool);
        bool isActive() const;
        int getNRubies() const;
        void addReward(const Reward&);
        void setDisplayMode(bool endOfGame);
        Side getSide() const;
        void setSide(Side);

        Player& operator=(const Player&);
        friend ostream& operator<<(ostream&, const Player&);
        bool operator<(const Player &rhs) const { return nRubies < rhs.getNRubies(); }


};

#endif // PLAYER_H
