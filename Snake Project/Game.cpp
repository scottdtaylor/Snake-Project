#include "Game.h"
#include<iostream>

Game::Game() {
	Snake = Snakey();
	food = Food();
	gameover = false;
	score = 0;
}

void Game::setup() {

}

void Game::drawboard() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width + 1; j++) {
			if (j == 0 || j == width)
				std::cout << '||';
		}
	}
}