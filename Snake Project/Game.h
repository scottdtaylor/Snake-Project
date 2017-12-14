#ifndef GAME_H
#define GAME_H

#include "Snakey.h"
#include "Food.h"

class Game {
private:

	Snakey Snake;
	Food food;
	bool gameover;
	int score;


public:
	Game();
	~Game();
	Game(const Game& copy) = delete;
	Game& operator=(const Game& assigned) = delete;
	void setup();
	void drawboard();
	void end_game();
	void generate_food();
	static const int width = 26;
	static const int height = 26;



	

};





#endif
