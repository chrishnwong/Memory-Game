#ifndef player_H
#define player_H

#include <string>

using std::string;
using std::endl;

class Player {
    string _name;
    enum BoardSide _side;
    int _rubyCount;
    bool _active;
    bool _end;//Does this belong here?

    public:
    enum BoardSide {
        Top,
        Bottom,
        Left,
        Right
        };

    Player();
    Player(string name, BoardSide side, int rubyCount = 0);
    string getName() const;
    void setActive(bool flag);
    bool isActive();
    int getNRubies() const;
    void addReward(const Reward& r);
    void setDisplayMode(bool endOfGame);

    string getEnumName() const;
    bool isEndOfGame() const;
    };
};

ostream& operator<<(ostream& os, const Player& p)  {
    if(p.isEndOfGame())
        os << p.name << ": " << p.getEnumName() << endl << endl;
    else
        os << p.name << ": " << p.getNRubies() << " rubies" << endl << endl;

    return os;
}

#endif
