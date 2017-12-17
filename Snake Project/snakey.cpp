#include "Snakey.h"
#include "Game.h"


class SnakeSetup {
public:
	SnakeSetup() {}
	
	void operator()(std::vector<triplet<int, int, char>>& spos) {
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
		}
		return;
	}
}s;

sdirection Snakey::wheregoing() {
	return going;
}

Snakey::Snakey() {
	
	s(spos);
	going = STOPPED;
	lastpos.first = 0;
	lastpos.second = 0;
	lastpos.third = 'o';
}

Snakey::Snakey(const Snakey& s) {
	this->spos.resize(s.spos.size());
	std::copy(s.spos.begin(), s.spos.end(), this->spos.begin());
	this->going = s.going;
	this->lastpos = s.lastpos;
}


Snakey& Snakey::operator=(Snakey s) {
	swap(s);
	return *this;
}
void Snakey::swap(Snakey& s) {
	
	std::swap(this->going, s.going);
	std::swap(this->spos, s.spos);
}
Snakey::~Snakey() {

}
