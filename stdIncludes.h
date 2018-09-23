#ifndef STD
#define STD

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "player.h"
#include "enemy.h"

extern std::vector<std::string> enemyOptions;
extern std::vector<std::string> enemyChoices;
extern std::vector<std::string> possibleMoves;
extern std::vector<std::string> mainLoopChoices;

std::string getText(const char* message);
std::string getResponse(const char* prompt, std::vector<std::string>& options);
std::string turnBeginner(int turn, Player& player, Enemy& opponent);
void turnDoer(std::string move, Player& player, Enemy& opponent);
int Battle(Player& player);
void Shop();

#endif