#include "main.h"

std::string getText(const char* message) {
	std::string input;

	std::cout << message;
	std::cin >> input;

	return input;
}

std::string getResponse(const char* prompt, std::vector<std::string>& options) {
	std::string response;
	while ( true ){
		std::cout << prompt << std::endl;

		std::cout << "(";
		for ( int i = 0; i < options.size(); i++){
			if ( i == options.size() - 1) std::cout << options[i];
			else std::cout << options[i] << ", ";
		}
		std::cout << ") ";
		std::cin >> response;

		if ( std::find( options.begin(), options.end(), response ) == options.end() )
			std::cout << "\nNo correct choice of that name. (Maybe capitalize the first letter?)\n";
		else break;
	}

	return response;
}

std::string turnBeginner(int turn, Player& player, Enemy& opponent) {
	std::cout << "\nTurn #" << turn << std::endl;
	std::cout << opponent.name << ": " << opponent.health << " health -@- You: " << player.health << " health" << std::endl;

	std::string move = getResponse("What move would you like to make this turn?", possibleMoves);
	return move;
}

void turnDoer(std::string move, Player& player, Enemy& opponent) {
	if ( move == "Attack" )			player.doDamage( opponent );
	else if ( move == "Pass" ) 	player.pass();

	if ( opponent.health > 0 ){
		int opponentAttackDamage = opponent.getDamageDone();
		if ( opponentAttackDamage == 0) std::cout << "The " << opponent.name << " missed!" << std::endl;
		else player.getHit( opponentAttackDamage );
	}
	else ;
}

int Battle(Player& player) {
	std::string enemyToFight = getResponse("\nWhat type of enemy would you like to fight today?", enemyChoices);
	Enemy opponent( enemyToFight, player.level );

	std::cout << "\nLet the battle begin!" << std::endl;

	int turn = 1;
	while ( opponent.health > 0 and player.health > 0 ){
		std::string turnMove = turnBeginner(turn, player, opponent);
		turnDoer(turnMove, player, opponent);

		turn++;
	}

	if ( player.health > 0 ) {
		std::cout << "\nCongratulations! You have defeated your opponent!" << std::endl;
		// setMoneyEarned( opponent, moneyEarned );
	}
	else {
		std::cout << "\nOh no! Looks like you were defeated." << std::endl;
	}

	return 1;
}