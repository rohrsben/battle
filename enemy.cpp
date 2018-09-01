#include "battle.h"

// specific initializers

void Enemy::initOgre(){
	health = 100;
	damageRange[0] = 10;
	damageRange[1] = 15;
	hitChance = 0.8;
	type = "Ogre";
	name = "Ogre";
}

void Enemy::initDragon(){
	health = 250;
	damageRange[0] = 15;
	damageRange[1] = 20;
	hitChance = 0.99;
	type = "Dragon";
	name = "Dragon";
}

void Enemy::initSlime(){
	health = 25;
	damageRange[0] = 5;
	damageRange[1] = 7;
	hitChance = 1;
	type = "Slime";
	name = "Slime";
}

void Enemy::initZombie(){
	health = 75;
	damageRange[0] = 10;
	damageRange[1] = 12;
	hitChance = 0.9;
	type = "Zombie";
	name = "Zombie";
}

void Enemy::initRandom(){
	std::string enemyType = ( *Random::get( enemyOptions ) );

	if 		( enemyType == "Ogre" ) 	initOgre();
	else if 	( enemyType == "Dragon" ) 	initDragon();
	else if 	( enemyType == "Slime" ) 	initSlime();
	else if 	( enemyType == "Zombie" )	initZombie();
}


// main initializer

Enemy::Enemy( std::string enemyType, int newLevel ){
	level = newLevel;
	if 		( enemyType == "Ogre" ) 	initOgre();
	else if 	( enemyType == "Dragon" ) 	initDragon();
	else if 	( enemyType == "Slime" ) 	initSlime();
	else if 	( enemyType == "Zombie" )	initZombie();

	else if 	( enemyType == "Random" )	initRandom();
}


// general funtions

void Enemy::getHit( int damageDone ){
	std::cout << "The " << name << " is hit for " << damageDone << " damage." << std::endl;
	health -= damageDone;
}

int Enemy::getDamageDone(){
	if ( Random::get<bool>( hitChance ))
		return ( Random::get( damageRange[0], damageRange[1] ) * level );
	else return 0;
}