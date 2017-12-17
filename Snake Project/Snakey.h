
#ifndef SNAKEY_H
#define SNAKEY_H

#include "quad.h"
#include <vector>
#include <utility>


enum sdirection { STOPPED = 0, UP, DOWN, LEFT, RIGHT };
class Snakey {
private:
	
	std::vector<quad<int,int, char, sdirection>> spos;
	quad <int, int, char, sdirection> lastpos;
	



public:
	Snakey();
	Snakey(const Snakey& s);
	Snakey& operator=(Snakey s);
	virtual ~Snakey();
	bool check_collision(std::vector<quad<int, int, char, sdirection>>::iterator begin, std::vector<quad<int, int, char, sdirection>>::iterator end);
	void swap(Snakey& s);
	friend class Game;
	

};







#endif 

