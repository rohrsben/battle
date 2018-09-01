#include "battle.h"

int main(){
	std::string name = getText("What is your name, fighter? ");
	Player player( name );
	
	Battle( player );

	return 0;
}