#include <string>

#ifndef FOOD_H
#define FOOD_H

class Food {
public:
	Food();
	virtual ~Food();
	Food(const Food& f);
	Food& operator=(Food f);

private:
	int foodx;
	int foody;
	char toeat;
	friend class Game;

};



#endif // !FOOD_H
