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
	void setup();
	void drawboard();
	void update();
	bool getstatus();

	static const int width = 40;
	static const int height = 20;



	

};





#endif
