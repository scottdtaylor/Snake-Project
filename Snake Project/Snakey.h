
#ifndef SNAKEY_H
#define SNAKEY_H

#include <vector>
#include <utility>

enum sdirection { STOPPED = 0, UP, DOWN, LEFT, RIGHT };
class Snakey {
private:
	std::pair<int, int> head;
	std::vector<std::pair<int, int>> tail;
	std::vector<char> snake;
	sdirection going;



public:
	Snakey();
	Snakey(const Snakey& s);
	Snakey& operator=(Snakey s);
	virtual ~Snakey();
	bool check_collision();
	void swap(Snakey& s);



};







#endif 

