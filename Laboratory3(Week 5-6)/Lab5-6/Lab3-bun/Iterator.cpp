#include "Iterator.h"

Iterator::Iterator()
{
	this->current = 0;
}

void Iterator::add(const Tutorial & tut)
{
	this->tutorials.add(tut);
}

Tutorial Iterator::getCurrentTutorial() 
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	return this->tutorials[this->current];
}

void Iterator::open()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.open();
}

void Iterator::next() {
	if (this->tutorials.getSize() == 0)
		return;
	this->current++;
	Tutorial currentSong = this->getCurrentTutorial();
	currentSong.open();
}

bool Iterator::isEmpty() {
	return this->tutorials.getSize() == 0;
}

void Iterator::emptyIterator() {
	while (!this->isEmpty())
		this->tutorials.deleteElem(0);
}