#ifndef GAME_H
#define GAME_H

#include "Snakey.h"
#include "Food.h"

class Game {
private:

	Snakey snake;
	Food food;
	bool gameon;
	int score;


public:
	Game();
	virtual ~Game();
	Game(const Game& copy) = delete;
	Game& operator=(const Game& assigned) = delete;
	void drawboard();
	void movesnake();
	void collisions();
	bool getstatus();

	static const int width = 30;
	static const int height = 13;



	

};





#endif
