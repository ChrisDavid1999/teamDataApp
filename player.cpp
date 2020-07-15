#include "player.h"

player::player()
{
    //ctor
}

player::player(std::string input)
{
    std::stringstream ss(input);
    std::string hold;
    int n = 0;
    std::string temp[3];
    while(getline(ss, hold, ','))
    {
        temp[n] = hold;
        n++;
    }

    position = temp[0];
    name = temp[1];
    rating = stoi(temp[2]);
}

void player::setName(std::string n)
{
    name = n;
}

std::string player::getName() const
{
    return name;
}

void player::setRating(int r)
{
    rating = r;
}

int player::getRating() const
{
    return rating;
}

void player::setPosition(std::string p)
{
    position = p;
}

std::string player::getPosition() const
{
    return position;
}
