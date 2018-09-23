#include "stdIncludes.h"

// initializer
Player::Player( std::string title ){
	if ( /* put save finding logic here */  0 ) {
		;// load the save
	}
	else {
		name = title;
		level = 1;
		health = 100;
		damageRange[0]= 7;
		damageRange[1] = 12;
		hitChance = 0.95;
	}
}

// general functions
void Player::getHit( int damageDone){
	std::cout << "You are hit for " << damageDone << " damage." << std::endl;
	health -= damageDone;
}

void Player::pass(){
	int healthRegained = 5;
	health += healthRegained;

	std::cout << "You have healed for " << healthRegained << " health." << std::endl;
}

void Player::kill() {
	dead = true;
}

void Player::save() {
	// TODO
}

void Player::deleteSave() {
	// TODO
}

int Player::getDamageDone(){
	int damageDone = 0;
	int baseDamage = Random::get( damageRange[0], damageRange[1] );
	if ( Random::get<bool>( hitChance ) ){
		damageDone = baseDamage * level;
	}

	return damageDone;
}