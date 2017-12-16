#include "Game.h"
#include<iostream>

Game::Game() {
	snake = Snakey();
	food = Food();
	gameon = true;
	score = 0;
}


//kbhit
//getch
Game::~Game() {

}

void Game::drawboard() {
	std::cout << "  ";
	for (int i = 0; i < width - 1; i++)
		std::cout << "_";
	std::cout << "\n";
	for (int i = 0; i < height+1; i++) {
		for (int j = 0; j < width + 1; j++) {
			if (j == 0 || j == width)
				std::cout << "||";
			else if (i == height)
				std::cout << '_';
			else if (i == food.foody && j == food.foodx)
				std::cout << food.toeat;
			else{
				for (int k = 0; k < snake.spos.size(); k++) {
					if (snake.spos[k].first == j && snake.spos[k].second == i) {
						std::cout << snake.snake[k];
						j++;
					}
					
									}
				std::cout << " ";
				}
				
		}
		std::cout << std::endl;
	
	}
	

}

void Game::update() {

}
bool Game::getstatus() {
	return gameon;
}