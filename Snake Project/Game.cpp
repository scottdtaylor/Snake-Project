#include "Game.h"
#include<iostream>
#include <conio.h>

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
	if (_kbhit()) {
		switch (_getch()) {
		case 'w': 
			snake.going = UP;
			break;
		case 'a':
			snake.going = LEFT;
			break;
		case 's':
			snake.going = DOWN;
			break;
		case 'd':
			snake.going = RIGHT;
			break;
		}
	}
	switch (snake.going) {
	case UP:
		snake.spos[0].second++;
		break;
	case LEFT:
		snake.spos[0].first--;
		break;
	case DOWN:
		snake.spos[0].second--;
		break;
	case RIGHT:
		snake.spos[0].first
	}
}
bool Game::getstatus() {
	return gameon;
}