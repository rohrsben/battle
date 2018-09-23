#ifndef ENEMY
#define ENEMY

#include "stdIncludes.h"

#include "libraries/effel/random.hpp"
using Random = effolkronium::random_static;

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

#endif