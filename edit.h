#ifndef EDIT_H
#define EDIT_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "team.h"
#include "player.h"

typedef std::map <int,team> teamInfo;

void editMenu(teamInfo &teams, int num);

void editOptions(std::string name);

void editTeam(teamInfo &teams);

void editTeamName(teamInfo &teams, int num);

void editPlayersMenu(teamInfo &teams, int num);

void printPlayers(teamInfo &teams, int num);

void editPlayerOptions(teamInfo &teams, int tNum, int pNum);

void displayTeams(teamInfo &teams);

void displayTeamsAndPlayers(teamInfo &teams);

void writeToTeams(teamInfo &teams);

void writePlayers(teamInfo &teams);

void createTeam(teamInfo &teams);

int getIntegerInput(int min, int max);

#endif // EDIT_H
