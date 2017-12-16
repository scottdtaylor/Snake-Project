#include "Snakey.h"
#include "Game.h"

class SnakeSetup {
public:
	SnakeSetup() {}
	template <typename positions>
	void operator()(std::vector<std::pair<positions, positions>>& spos) {
		spos.resize(4);
		spos[0].first = Game::width / 2;
		spos[0].second = Game::height / 2;
		spos[1].first = spos[0].first;
		spos[1].second = spos[0].second + 1;
		spos[2].first = spos[1].first;
		spos[2].second = spos[1].second + 1;
		spos[2].first = spos[1].first;
		spos[2].second = spos[1].second + 1;
		return;
	}
}s;

Snakey::Snakey() {
	snake = std::vector<char>();
	s(spos);
	snake.push_back('@');
	snake.push_back('o');
	snake.push_back('o');
	snake.push_back('o');
	going = STOPPED;
}

Snakey::Snakey(const Snakey& s) {
	this->spos.resize(s.spos.size());
	std::copy(s.spos.begin(), s.spos.end(), this->spos.begin());
	this->snake.resize(s.snake.size());
	std::copy(s.snake.begin(), s.snake.end(), this->snake.begin());
	this->going = s.going;
}

Snakey& Snakey::operator=(Snakey s) {
	swap(s);
	return *this;
}
void Snakey::swap(Snakey& s) {
	
	std::swap(this->going, s.going);
	std::swap(this->snake, s.snake);
	std::swap(this->spos, s.spos);
}
Snakey::~Snakey() {

}
