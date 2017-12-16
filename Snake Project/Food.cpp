#include "Food.h"
#include "Game.h"
#include <cstdlib> 
#include <utility>

Food::Food() {
	foodx = 1+ (rand() % (Game::width-1));
	foody =1 + (rand() % (Game::height -1) );
	toeat = '*';
}

Food::Food(const Food& f) {
	this->foodx = f.foodx;
	this->foody = f.foody;
}

Food& Food::operator=(Food f) {
	std::swap(this->foodx, f.foodx);
	std::swap(this->foody, f.foody);
	return *this;
}


 Food::~Food(){


}
