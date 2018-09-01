#include "libraries/effel/random.hpp"
using Random = effolkronium::random_static;

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

static std::vector<std::string> enemyOptions =  { "Ogre", "Dragon", "Slime", "Zombie" };
static std::vector<std::string> enemyChoices =  { "Random", "Ogre", "Dragon", "Slime", "Zombie" };
static std::vector<std::string> possibleMoves = { "Attack", "Pass" };

class Enemy {
public:
	int health;
	int level;
	int damageRange[2];
	double hitChance;
	std::string type;
	std::string name;
private:
	void initOgre();
	void initDragon();
	void initSlime();
	void initZombie();
	void initRandom();
public:
	Enemy( std::string enemyType, int newLevel );
	void getHit( int damageDone );
	int getDamageDone();
};

class Player {
public:
	int health = 100;
	int level = 1;
	double hitChance = 0.95;
	std::string name;

	Player( std::string title );
	void getHit( int damageDone);
	void pass();
	void doDamage( Enemy& opponent );
};

std::string getText(const char* message);
std::string getResponse(const char* prompt, std::vector<std::string>& options);
std::string turnBeginner(int turn, Player& player, Enemy& opponent);
void turnDoer(std::string move, Player& player, Enemy& opponent);
int Battle(Player& player);