#include <iostream>
#include <vector>
#include "Game.h"
#include "Snakey.h"
#include "Food.h"
#include<chrono>





int main() {

	Game game;
	
	while (game.getstatus()) {
		system("CLS");
		game.drawboard();
		game.movesnake();
		
	}
	system("PAUSE");
	return 0;
}