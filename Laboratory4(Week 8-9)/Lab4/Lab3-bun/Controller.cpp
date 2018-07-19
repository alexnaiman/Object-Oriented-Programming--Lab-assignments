#include "Controller.h"
#include <algorithm>
#include <iterator>



Controller::Controller(const Controller & c)
{
	repo = c.repo;
	tutoritalsIter = c.tutoritalsIter;
	watchlist = c.watchlist;
}

Controller::~Controller()
{
	delete repo;
	delete watchlist;
}

Controller & Controller::operator=(const Controller & c)
{
	repo = c.getRepo();
	//repo = c.getRepo();
	tutoritalsIter = c.tutoritalsIter;
	watchlist = c.watchlist;
	return *this;
}

bool Controller::addTutorialToRepository(Tutorial& t)
{
	return this->repo->addTutorial(t);
}

bool Controller::removeTutorialFromRepository(const std::string & presenter, const std::string & title)
{
	return this->repo->removeTutorial(presenter, title);
}

bool Controller::updateTutorialFromRepository(const std::string & presenter, const std::string & title, Tutorial& nT)
{
	Tutorial t = this->repo->findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" || t.getTitle() == "")
		return false;
	Tutorial newT = this->repo->findByPresenterAndTitle(nT.getPresenter(), nT.getTitle());
	if ((newT.getPresenter() != "" || newT.getTitle() != "") && (nT.getPresenter() != presenter && nT.getTitle() != title))
		return false;
	this->removeTutorialFromRepository(presenter, title);
	this->addTutorialToRepository(nT);
//	this->addTutorialToRepository(newName, newTitle, minutes, seconds, noLikes, source);
	return true;
}

void Controller::addTutorialToWatchlist(const Tutorial & tutorial)
{
	this->watchlist->addTutorial(tutorial);
}

void Controller::configIterator(const std::string & presenter)
{
	this->tutoritalsIter.emptyIterator();
	std::vector<Tutorial>* s = this->repo->getTutorials();
	if (presenter.size() == 0) {
		for (auto& it : *s) {
			this->tutoritalsIter.add(it);
		}
	}
	else {
		for (auto& it : *s) {
			if (it.getPresenter() == presenter)
				this->tutoritalsIter.add(it);
		}
	}
}

Tutorial Controller::getCurrentTutorial()
{
	return this->tutoritalsIter.getCurrentTutorial();
}



void Controller::startIteration() {
	this->tutoritalsIter.open();
}

bool Controller::deleteTutorialFromWatchlist(const Tutorial & tutorial)
{
	return this->watchlist->removeTutorial(tutorial.getPresenter(), tutorial.getTitle());
}

void Controller::next()
{
	this->tutoritalsIter.next();
}

bool Controller::likeTutorial()
{
	Tutorial t = this->getCurrentTutorial();
	t.like();

	return this->updateTutorialFromRepository(t.getPresenter(), t.getTitle(), Tutorial{t.getTitle(),t.getPresenter(),t.getDuration(),t.getNoLikes(),t.getSource(),t.getNoViews()});


}

void Controller::toFile()
{
	//repo->repoToFile();
}

std::vector<Tutorial> Controller::filter(int value)
{
	std::vector<Tutorial>* v = repo->getTutorials();
	std::vector<Tutorial> n{};
	auto it = std::copy_if(v->begin(), v->end(), std::back_inserter(n), [&value](Tutorial& t) {return t < value; });
	return n;
}

void Controller::display() {
	this->watchlist->display();
}