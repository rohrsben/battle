#include "battle.h"

// initializer
Player::Player( std::string title ){
	name = title;
	// TODO: add save/load function here
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

void Player::doDamage( Enemy& opponent ){
	int baseDamage = Random::get(10, 15);
	if ( Random::get<bool>( hitChance ) ){
		int damage = baseDamage * level;
		opponent.getHit( damage );
	}
	else std::cout << "You missed!" << std::endl;
}
