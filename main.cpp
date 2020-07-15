#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "team.h"
#include "player.h"
#include "edit.h"

void printMenuOptions();

void loadTeams(teamInfo &teams);

void getTeamsData(std::ifstream &info, teamInfo &teams, int &num);
bool menuLoop(teamInfo &teams);

void howToUse();

int main()
{
    teamInfo teams;
    bool quit = false;
    loadTeams(teams);

    do
    {
        quit = menuLoop(teams);
    }
    while(!quit);

    return 0;
}

void loadTeams(teamInfo &teams)
{
    std::string name;
    std::ifstream data("data/teams.txt");
    int num = 1;
    while(getline(data, name))
    {
        std::ifstream info("data/teams/" + name + ".txt");
        getTeamsData(info, teams, num);
        info.close();
    }
    data.close();
}

void getTeamsData(std::ifstream &info, teamInfo &teams, int &num)
{
    std::vector<player> p;
    std::string name, hold;
    getline(info, name);

    while(getline(info, hold))
    {
        std::cout << hold << std::endl;
        player temp(hold);
        p.push_back(temp);
    }
    std::cout << "Size: " << p.size() << std::endl;
    team t(name, p);
    teams.insert(std::pair<int, team>(num, t));
    num ++;
}

void printMenuOptions()
{
    std::cout << "1: How to use this program" << std::endl;
    std::cout << "2: Display Teams" << std::endl;
    std::cout << "3: Display Teams and Their Players" << std::endl;
    std::cout << "4: Edit Team and Player Information(IN DEVELOPMENT)" << std::endl;
    std::cout << "5: Create Team" << std::endl;
    std::cout << "6: Exit Program" << std::endl;
}

bool menuLoop(teamInfo &teams)
{
    printMenuOptions();
    int choice = getIntegerInput(1, 6);
    bool quit = false;
    switch(choice)
    {
            case 1:
                howToUse();
                break;
            case 2:
                displayTeams(teams);
                break;
            case 3:
                displayTeamsAndPlayers(teams);
                break;
            case 4:
                break;
            case 5:
                createTeam(teams);
                break;
            case 6:
                writeToTeams(teams);
                writePlayers(teams);
                quit = true;
                break;
            default:
                std::cerr << "ERROR 001! Something has gone wrong in the menu!" << std::endl;
                break;
    }

    return quit;
}

void howToUse()
{
    std::cout << "IN DEVELOPMENT! EXPLAINS HOW TO USE THE PROGRAM!" << std::endl;
}
