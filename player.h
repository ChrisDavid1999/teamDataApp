#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>
#include <iostream>

class player
{
    public:
        player();
        player(std::string input);

        void setName(std::string n);
        std::string getName() const;

        void setRating(int r);
        int getRating() const;

        void setPosition(std::string p);
        std::string getPosition() const;

    private:
        std::string name;
        int rating;
        std::string position;
};

#endif // PLAYER_H
