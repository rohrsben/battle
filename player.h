#ifndef PLAYER_H
#define PLAYER

#include "stdIncludes.h"
#include "enemy.h"

#include "libraries/effel/random.hpp"
using Random = effolkronium::random_static;

class Player {
public:
	int health, level;
	int damageRange[2];
	double hitChance;
	std::string name;
	bool dead = false;

	Player( std::string title );

	void getHit( int damageDone );
	void pass();
	void save();
	void kill();
	void deleteSave();

	int getDamageDone();
};

#endif