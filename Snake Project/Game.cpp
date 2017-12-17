#include "Game.h"
#include<iostream>
#include <conio.h>
#include <algorithm>
#include<numeric>
#include<utility>
#include"triplet.h"


class snakesort {
public:
	snakesort() {

	}
	bool operator()(triplet<int, int, char> a, triplet<int, int, char> b, sdirection d) {
		switch (d) {

		}
	}

}ssort;




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
	sdirection whereto = snake.wheregoing();
	std::vector<triplet<int, int, char>> copy = snake.spos;
	std::sort(copy.begin(), copy.end(), [&](triplet<int, int, char> a, triplet<int, int, char> b)
	{switch (whereto) { case UP: ssort(a, b, UP); break; case LEFT: ssort(a, b, LEFT); break; case DOWN: ssort(a, b, DOWN); break; case RIGHT: ssort(a, b, RIGHT); break; case STOPPED: ssort(a, b, STOPPED); }});
	for (int l = 0; l < snake.spos.size(); l++) {
		std::cout << snake.spos[l].first << ',' << snake.spos[l].second << "  ";
	}
	std::cout << '\n';
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

				for (int k = 0; k < copy.size(); k++) {
					if (copy[k].first == j && copy[k].second == i) {
						std::cout << copy[k].third;
						j++;
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