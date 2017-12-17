#include "Snakey.h"
#include "Game.h"


class SnakeSetup {
public:
	SnakeSetup() {}
	
	void operator()(std::vector<quad<int, int, char, sdirection>>& spos) {
		spos.resize(4);
		spos[0].first = Game::width / 2;
		spos[0].second = Game::height / 2;
		spos[1].first = spos[0].first;
		spos[1].second = spos[0].second + 1;
		spos[2].first = spos[1].first;
		spos[2].second = spos[1].second + 1;
		spos[3].first = spos[2].first;
		spos[3].second = spos[2].second + 1;
		spos[0].third = '@';
		for (int i = 1; i < spos.size(); i++) {
			spos[i].third = 'o';
			spos[i-1].fourth = UP;
		}
		spos[spos.size() - 1].fourth = UP;
		return;
	}
}s;



Snakey::Snakey() {
	
	s(spos);
	lastpos.first = 0;
	lastpos.second = 0;
	lastpos.third = 'o';
	
}

Snakey::Snakey(const Snakey& s) {
	this->spos.resize(s.spos.size());
	std::copy(s.spos.begin(), s.spos.end(), this->spos.begin());
	this->lastpos = s.lastpos;
}


Snakey& Snakey::operator=(Snakey s) {
	swap(s);
	return *this;
}
void Snakey::swap(Snakey& s) {
	std::swap(lastpos, s.lastpos);
	std::swap(this->spos, s.spos);
}
bool Snakey::check_collision(std::vector<quad<int, int, char, sdirection>> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[0].first == v[i].first && v[0].second == v[i].second)
			return true;
	}
	return false;
}
Snakey::~Snakey() {

}
