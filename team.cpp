#include "team.h"
team::team()
{
    name = "";
    pCount = 0;
}

team::team(std::string n)
{
    name = n;
    pCount = 0;
}

team::team(std::string n, std::vector<player> &p)
{
    name = n;
    for(int i = 0; i < p.size(); i++)
    {
        std::cout << p[i].getName() << std::endl;
        players[i] = p[i];
    }

    if(p.size() < 11)
        pCount = p.size();
    else
        pCount = 11;
}

void team::setName(std::string n)
{
    name = n;
}

std::string team::getName() const
{
    return name;
}

void team::setPlayer(int i, player p)
{
    players[i] = p;
}

player team::getPlayer(int i)
{
    return players[i];
}

int team::getCount() const
{
    return pCount;
}
