#include "Game.h"
#include<iostream>
#include <conio.h>
#include <algorithm>
#include<numeric>
#include<utility>

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
					if (snake.spos[k].first == j && snake.spos[k].second == i && snake.going != RIGHT) { //check for a triple class, use that and sort lol
						std::cout << snake.snake[k];
						j++;
					}
					for (int k = snake.spos.size() - 1; k > -1; k--) {
						if (snake.spos[k].first == j && snake.spos[k].second == i && snake.going == RIGHT) {
							std::cout << snake.snake[k];
							j++;
						}
				}
					
					
									}
				std::cout << " ";
				}
				
		}
		std::cout << std::endl;
	
	}
	std::cout << "Score: " << score;

}

void Game::movesnake() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (snake.going == DOWN)
				break;
			snake.going = UP;
			break;
		case 'a':
			if (snake.going == RIGHT)
				break;
			snake.going = LEFT;
			break;
		case 's':
			if (snake.going == UP)
				break;
			snake.going = DOWN;
			break;
		case 'd':
			if (snake.going == LEFT)
				break;
			snake.going = RIGHT;
			break;
		}
	}
	if (snake.going != STOPPED) {
		snake.lastpos = snake.spos[snake.spos.size() - 1];
		for (int i = snake.spos.size() - 1; i > 0 ; i--) {
			snake.spos[i] = snake.spos[i - 1];
			
		}
	}
		switch (snake.going) {
		case UP:
			snake.spos[0].second--;
			break;
		case LEFT:
			snake.spos[0].first--;
			break;
		case DOWN:
			snake.spos[0].second++;
			break;
		case RIGHT:
			snake.spos[0].first++;
			break;
		case STOPPED:
			break;

		}
		
}
void Game::collisions() {
	if(snake.spos[0].first == food.foodx && snake.spos[0].second == food.foody){
		score += 1;
		food = Food();
		snake.snake.push_back('o');
		snake.spos.push_back(snake.lastpos);

	}
}

bool Game::getstatus() {
	return gameon;
}
/*Things to implement:
std::bind, possibly using a lambda, can use in the update(), if lambda can access members.
smart pointers
iterator discussion
memory management by try catch
qt implementation
try doing some inheritance stuff by creating opposite snake

*/