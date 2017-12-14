#include "Snakey.h"
#include "Game.h"

Snakey::Snakey() {
	head.first = Game::width / 2;
	head.second = Game::height / 2;
	tail[1].first = head.first;
	tail[1].second = head.second + 1;
	tail[2].first = tail[1].first;
	tail[2].second = tail[1].second + 1;
	tail[3].first = tail[2].first;
	tail[3].second = tail[2].second + 1;
	snake.push_back('@');
	snake.push_back('o');
	snake.push_back('o');
	snake.push_back('o');
	going = STOPPED;
}

Snakey::Snakey(const Snakey& s) {
	this->head = s.head;
	this->tail.resize(s.tail.size());
	std::copy(s.tail.begin(), s.tail.end(), this->tail.begin());
	this->snake.resize((s.snake.size());
	std::copy(s.snake.begin(), s.snake.end(), this->snake.begin());
	this->going = s.going;
}

Snakey& Snakey::operator=(Snakey s) {
	swap(s);
	return *this;
}
void Snakey::swap(Snakey& s) {
	std::swap(this->head, s.head);
	std::swap(this->going, s.going);
	std::swap(this->snake, s.snake);
	std::swap(this->tail, s.tail);
}
Snakey::~Snakey() {

}
