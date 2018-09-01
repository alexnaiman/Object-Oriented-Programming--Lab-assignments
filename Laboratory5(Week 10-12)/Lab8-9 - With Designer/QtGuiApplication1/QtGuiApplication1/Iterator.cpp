#include "Iterator.h"

Iterator::Iterator()
{
	this->current = 0;
}

void Iterator::add(const Tutorial & tut)
{
	this->tutorials.push_back(tut);
}

Tutorial& Iterator::getCurrentTutorial()
{
	if (this->tutorials.size() == 0) return Tutorial{};
	if (this->current == this->tutorials.size())
		this->current = 0;
	return this->tutorials[this->current];
}

void Iterator::open()
{
	if (this->tutorials.size() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.open();
}

void Iterator::next() {
	if (this->tutorials.size() == 0)
		return;
	this->current++;
	Tutorial currentSong = this->getCurrentTutorial();
	currentSong.open();
}

bool Iterator::isEmpty() {
	return this->tutorials.size() == 0;
}

void Iterator::emptyIterator() {
	this->tutorials = std::vector<Tutorial>();
}