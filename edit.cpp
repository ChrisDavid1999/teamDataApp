#include "edit.h"

void editMenu(teamInfo &teams, int num)
{
    bool menu = false;
    int choice;

    do
    {
        editOptions(teams[num].getName());
        choice = getIntegerInput(1, 3);
        switch(choice)
        {
            case 1:
                editTeamName(teams, num);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                menu = true;
                break;
        }
    }
    while(!menu);
}

void editOptions(std::string name)
{
    std::cout << "Edit " << name << std::endl;
    std::cout << "1: Edit Team Name" << std::endl;
    std::cout << "2: Edit a player" << std::endl;
    std::cout << "3: Create a new player" << std::endl;
    std::cout << "4: Transfer a player(IN DEVELOPMENT)" << std::endl;
    std::cout << "5: Exit Edit Menu" << std::endl;
}

void editTeam(teamInfo &teams)
{
    bool found;
    int num;

    std::cout << "TEAMS" << std::endl;
    for(int i = 1; i < teams.size()+1; i++)
    {
        std::cout << i << "." << teams[i].getName() << std::endl;
    }
    std::cout << std::endl;
    std::cout << '\n' << "Please enter a number for the team you wish to edit: ";
    num = getIntegerInput(1, teams.size()+1);
    std::cout << std::endl;
    std::cout << std::endl;

    editMenu(teams, num);
}

void editTeamName(teamInfo &teams, int num)
{
    std::string name;
    bool nameFound = false;

    std::cout << "Please enter a new name for the team " << teams[num].getName() << ":";
    std::cin >> name;
    std::cout << std::endl;
    teams[num].setName(name);
    std::cout << "The team name has been set to " << teams[num].getName() << std::endl;
    std::cout << std::endl;
}

void editPlayersMenu(teamInfo &teams, int num)
{
    bool menu = false;
    int choice;

    if(teams[num].getCount() == 0)
    {
        menu = true;
        std::cout << "This team has no players to edit" << std::endl;
    }
    else
    {
        printPlayers(teams, num);
        std::cout << "Please select a player from this list:" << std::endl;
        choice = getIntegerInput(1, teams[num].getCount());
        editPlayerOptions(teams, num, choice-1);
    }

}

void printPlayers(teamInfo &teams, int num)
{
    for(int x = 0; x < teams[num].getCount(); x++)
    {
        player temp = teams[num].getPlayer(x);
        std::cout << x+1 << "." << temp.getName() << "," << temp.getPosition() << "," << temp.getRating() << std::endl;
    }
}

void editPlayerOptions(teamInfo &teams, int tNum, int pNum)
{

}

void displayTeams(teamInfo &teams)
{
    for(int i = 1; i < teams.size()+1; i++)
    {
        std::cout << "  " << teams[i].getName() << std::endl;
    }
    std::cout << std::endl;
}

void displayTeamsAndPlayers(teamInfo &teams)
{
    for(int i = 1; i < teams.size()+1; i++)
    {
        std::cout << "  " << teams[i].getName() << std::endl;
        for(int x = 0; x < teams[i].getCount(); x++)
        {
            player temp = teams[i].getPlayer(x);
            std::cout << "      POS: " << temp.getPosition() << " -- NAME: " << temp.getName() << " -- RATING: " << temp.getRating() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void writeToTeams(teamInfo &teams)
{
    std::ofstream os("data/teams.txt");
    for(int i = 1; i < teams.size()+1; i++)
    {
        os << teams[i].getName() << std::endl;
    }
    os.close();
}

void writePlayers(teamInfo &teams)
{
    for(int i = 1; i < teams.size()+1; i++)
    {
        std::ofstream t("data/teams/" + teams[i].getName() + ".txt");
        t << teams[i].getName() << std::endl;
        for(int x = 0; x < teams[i].getCount();x++)
        {
            player temp = teams[i].getPlayer(x);
            t << temp.getPosition() << "," << temp.getName() << "," << temp.getRating() << std::endl;
        }
        t.close();
    }
}

void createTeam(teamInfo &teams)
{
    std::string name;
    bool newTeam = false;

    do
    {
        std::cout << "Please enter a name for the new team: ";
        std::cin >> name;
        std::cout << std::endl;

        for(int i = 1; i < teams.size()+1; i++)
        {
            if(teams[i].getName() != name)
            {
                team t(name);
                teams.insert(std::pair<int, team>(teams.size()+1, t));
                std::cout << "The team " << name << " has been created" << std::endl;
                newTeam = true;
                break;
            }
        }

        if(!newTeam)
        {
            std::cout << "Sorry the team name " << name << " already exists, please select another name!" << std::endl;
            std::cin.clear();
        }
    }
    while(!newTeam);
    std::cout << std::endl;
}

int getIntegerInput(int min, int max)
{
    int choice;
    bool correct = false;

    while(!correct)
    {
        std::cout << "Please enter a option from the menu: ";
        std::cin >> choice;
        std::cout << std::endl;
        if(choice < min || choice > max)
        {
            std::cout << "Error! Please enter a valid input!" << std::endl;
            std::cin.clear();
        }else
            correct = true;
    }
}
