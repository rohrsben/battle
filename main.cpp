#include "stdIncludes.h"

int main(){
	std::string name = getText("What is your name, fighter? ");
	Player player( name );
	
	// the main game loop
	while ( player.dead == true ){
		std::string mainChoice = getResponse("What would you like to do?", mainLoopChoices);

		if ( mainChoice == "Visit the shop" )          std::cout << "N/A\n";
		else if ( mainChoice == "Battle an enemy" )    Battle( player );
		else if ( mainChoice == "Save the game" )      std::cout << "N/A\n";
		else if ( mainChoice == "Exit" ) {
			std::cout << "See you soon, " << player.name << "!\n" << std::endl;
			break;
		}
	}

	std::cout << "We'll see you in your next life, " << player.name << std::endl;
	player.deleteSave();

	return 0;
}