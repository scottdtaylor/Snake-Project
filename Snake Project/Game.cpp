#include "Game.h"
#include<iostream>
#include <conio.h>
#include <algorithm>
#include<numeric>
#include<utility>
#include"quad.h"




Game::Game() {

	snake = Snakey();
	food = Food();
	gameon = true;
	score = 0;
}

bool operator<(quad<int,int,char,sdirection> a, quad<int, int, char, sdirection> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;

}


//kbhit
//getch
Game::~Game() {

}

void Game::drawboard() {
	std::vector<quad<int, int, char, sdirection>> copy = snake.spos;
	std::stable_sort(copy.begin(), copy.end());

	bool printeds = false;
	bool fruitbysnake = false;

	std::cout << "  ";
	for (int i = 0; i < width - 1; i++)
		std::cout << "#";
	std::cout << "\n";
	for (int i = 0; i < height+1; i++) {
		for (int j = 0; j < width + 1; j++) {
			printeds = false;
			fruitbysnake = false;
			if (j == 0 || j == width)
				std::cout << "#";
			else if (i == height)
				std::cout << '#';
			else if (i == food.foody && j == food.foodx)
				std::cout << food.toeat;
			else{
				
				for (int k = 0; k < copy.size(); k++) {
					
					
					if (copy[k].first == j && copy[k].second == i) {
						std::cout << copy[k].third;
						printeds = true;
						break;
					}
				}
				if (printeds)
					continue;
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
			if (snake.spos[0].fourth == DOWN)
				break;
			snake.spos[0].fourth = UP;
			break;
		case 'a':
			if (snake.spos[0].fourth == RIGHT)
				break;
			snake.spos[0].fourth = LEFT;
			break;
		case 's':
			if (snake.spos[0].fourth == UP)
				break;
			snake.spos[0].fourth = DOWN;
			break;
		case 'd':
			if (snake.spos[0].fourth == LEFT)
				break;
			snake.spos[0].fourth = RIGHT;
			break;
		}
	}
	snake.lastpos = snake.spos[snake.spos.size() - 1];
	for (int i = snake.spos.size() - 1; i > 1; i--) {
		snake.spos[i] = snake.spos[i - 1];
	}
	snake.spos[1].first = snake.spos[0].first;
	snake.spos[1].second = snake.spos[0].second;
	snake.spos[0].third = snake.spos[0].third;
	
		switch (snake.spos[0].fourth) {
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

		}
		
}
void Game::collisions() {
	if(snake.spos[0].first == food.foodx && snake.spos[0].second == food.foody){
		score += 1;
		food = Food();
		snake.lastpos.fourth = snake.spos[snake.spos.size() - 1].fourth;
		snake.spos.push_back(snake.lastpos);
	}
	else if (snake.spos[0].first == 0 || snake.spos[0].first == width || snake.spos[0].second == -1 || snake.spos[0].second == height ) {
		gameon = false;
	}
	else if (snake.check_collision(snake.spos.begin(), snake.spos.end())) {
		gameon = false;
	}
}

bool Game::getstatus() {
	return gameon;
}
int Game::getscore() {
	return score;
}
/*Things to implement:
std::bind, possibly using a lambda, can use in the update(), if lambda can access members.
smart pointers
iterator discussion
memory management by try catch
qt implementation
try doing some inheritance stuff by creating opposite snake

*/