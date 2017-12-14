#include "Food.h"
#include "Game.h"
#include <cstdlib> 
#include <utility>

Food::Food() {
	foodx = (rand() % Game::width-1) + 1;
	foody = (rand() % Game::height - 1) +1;

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
