#include "stdIncludes.h"
#include <limits>

#include "libraries/effel/random.hpp"
using Random = effolkronium::random_static;

//variables
std::vector<std::string> enemyOptions =    { "Ogre", "Dragon", "Slime", "Zombie" };
std::vector<std::string> enemyChoices =    { "Random", "Ogre", "Dragon", "Slime", "Zombie" };
std::vector<std::string> possibleMoves =   { "Attack", "Pass" };
std::vector<std::string> mainLoopChoices = { "Visit the shop", "Battle an enemy", "Save the game", "Exit" };

// functions
std::string getText(const char* message) {
	std::string input;

	std::cout << message;
	std::getline(std::cin, input);

	return input;
}

std::string getResponse(const char* prompt, std::vector<std::string>& options) {
	std::string response;
	std::cout << std::endl << prompt << std::endl;

	for (int i = 0; i < options.size(); i++) {
		std::cout << "  " << i+1 << ": " << options[i] << std::endl;
	}

	while ( std::find( options.begin(), options.end(), response ) == options.end() ) {
		int choice;
		std::cout << "Number of choice > ";

		std::cin >> choice;
		if ( std::cin.fail() or choice > options.size() ) {
			std::cout << "Please enter a valid choice.\n" << std::endl;
			std::cin.clear();
			std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
		} else {

			response = options[choice-1];
		}
	}

	return response;
}

void turnDoer(Player& player, Enemy& opponent, int turn) {
	std::cout << "\nTurn #" << turn << std::endl;
	std::cout << opponent.name << ": " << opponent.health << " health -@- You: " << player.health << " health" << std::endl;

	std::string move = getResponse("What move would you like to make this turn?", possibleMoves);

	if ( move == "Attack" ) {
		int damageDone = player.getDamageDone();
		if ( damageDone > 0 ) {
			std::cout << "You hit the " << opponent.name << " for " << damageDone << " damage." << std::endl;
			opponent.getHit( damageDone );
		}
		else std::cout << "You missed!";
	}
	else if ( move == "Pass" ) 	player.pass();

	if ( opponent.health > 0 ){
		int opponentAttackDamage = opponent.getDamageDone();
		if ( opponentAttackDamage == 0) std::cout << "The " << opponent.name << " missed!" << std::endl;
		else player.getHit( opponentAttackDamage );
	}
	std::cout << std::endl;
}

int Battle(Player& player) {
	std::string enemyToFight = getResponse("What type of enemy would you like to fight today?", enemyChoices);
	Enemy opponent( enemyToFight, player.level );

	std::cout << "\n\nLet the battle begin!" << std::endl;

	int turn = 1;
	while ( opponent.health > 0 and player.health > 0 ){
		turnDoer(player, opponent, turn);
		turn++;
	}

	if ( player.health > 0 ) {
		std::cout << "Congratulations! You have defeated your opponent!\n" << std::endl;
		// setMoneyEarned( opponent, moneyEarned );
	} else {
		std::cout << "Oh no! Looks like you were defeated.\n" << std::endl;
	}

	return 1;
}

void Shop(){
	// TODO
}