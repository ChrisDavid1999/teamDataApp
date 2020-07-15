#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <vector>
#include <iostream>
#include "player.h"

class team
{
    public:
        team();
        team(std::string n);
        team(std::string n, std::vector<player> &p);

        void setName(std::string n);
        std::string getName() const;

        void setPlayer(int i, player p);
        player getPlayer(int i);

        int getCount() const;

    private:
        std::string name;
        player players[11];
        int pCount;
};

#endif // TEAM_H
