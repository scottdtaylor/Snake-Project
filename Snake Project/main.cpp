#include <iostream>
#include <vector>
#include "Game.h"
#include "Snakey.h"
#include "Food.h"
#include<chrono>
#include <utility>




//test
int main() {
	

	Game game;
	
	while (game.getstatus()) {
		system("CLS");
		game.drawboard();
		game.movesnake();
		game.collisions();
		_sleep(500);
		
	}
	system("PAUSE");
	return 0;
}