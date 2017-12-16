
#ifndef SNAKEY_H
#define SNAKEY_H

#include "triplet.h"
#include <vector>
#include <utility>


enum sdirection { STOPPED = 0, UP, DOWN, LEFT, RIGHT };
class Snakey {
private:
	
	std::vector<triplet<int,int, char>> spos;
	triplet <int, int, char> lastpos;
	sdirection going;



public:
	Snakey();
	Snakey(const Snakey& s);
	Snakey& operator=(Snakey s);
	virtual ~Snakey();
	bool check_collision();
	void swap(Snakey& s);
	friend class Game;
	

};







#endif 

