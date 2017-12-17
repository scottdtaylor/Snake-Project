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
	int getscore();

	static const int width = 33;
	static const int height = 14;



	

};





#endif
