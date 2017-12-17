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
		_sleep(50);
		
	}
	std::cout << '\n' << "You lose :(   Your score is: " << game.getscore() << std::endl;
	system("PAUSE");
	return 0;
}