#include "Controller.h"

bool Controller::addTutorialToRepository(const std::string& presenter, const std::string& title, double minutes, double seconds, double noLikes, const std::string& source, double noViews)
{
	Tutorial t{ title, presenter, Duration{ minutes, seconds },noLikes, source };
	return this->repo.addTutorial(t);
}

bool Controller::removeTutorialFromRepository(const std::string & presenter, const std::string & title)
{
	return this->repo.removeTutorial(presenter, title);
}

bool Controller::updateTutorialFromRepository(const std::string & presenter, const std::string & title, double minutes, double seconds, double noLikes, const std::string & source, const std::string newName, const std::string newTitle)
{
	Tutorial t = this->repo.findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" || t.getTitle() == "")
		return false;
	Tutorial newT = this->repo.findByPresenterAndTitle(newName, newTitle);
	if ((newT.getPresenter() != "" || newT.getTitle() != "") && (newName != presenter && newTitle != title))
		return false;
	this->removeTutorialFromRepository(presenter, title);
	this->addTutorialToRepository(newName, newTitle, minutes, seconds, noLikes, source);

	return true;
}

void Controller::addTutorialToWatchlist(const Tutorial & tutorial)
{
	this->watchlist.addTutorial(tutorial);
}

void Controller::configIterator(const std::string & presenter)
{
	this->tutoritalsIter.emptyIterator();
	DynamicVector<Tutorial> s = this->repo.getTutorials();
	if (presenter.size() == 0) {
		for (int i = 0; i < s.getSize(); i++) {
			this->tutoritalsIter.add(s[i]);
		}
	}
	else {
		for (int i = 0; i < s.getSize(); i++) {
			if (s[i].getPresenter()==presenter)
				this->tutoritalsIter.add(s[i]);
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
	return this->watchlist.removeTutorial(tutorial.getPresenter(), tutorial.getTitle());
}

void Controller::next()
{
	this->tutoritalsIter.next();
}

bool Controller::likeTutorial()
{
	Tutorial t = this->getCurrentTutorial();
	t.like();
	
	return this->updateTutorialFromRepository(t.getPresenter(), t.getTitle(), t.getDuration().getMinutes(), t.getDuration().getSeconds(), t.getNoLikes(), t.getSource(), t.getPresenter(), t.getTitle());


}

DynamicVector<Tutorial> Controller::filter(int value)
{
		DynamicVector<Tutorial> v = repo.getTutorials();
		DynamicVector<Tutorial> n{};
		for (int i = 0; i < v.getSize(); i++) {
			if (v[i] < value)
				n.add(v[i]);
		}
		return n;
}
