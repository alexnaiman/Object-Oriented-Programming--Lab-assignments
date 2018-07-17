#include "Repo.h"


bool Repository::addTutorial(const Tutorial & t)
{
	Tutorial tut = findByPresenterAndTitle(t.getPresenter(), t.getTitle());
	if (tut.getPresenter() != "" || tut.getSource() != "")
		return false;
	this->tutorials.add(t);
	return true;
}


Tutorial Repository::findByPresenterAndTitle(const std::string& presenter, const std::string& title) {
	Tutorial* tutorialsInDynamicVector = this->tutorials.getAllElems();

	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		Tutorial s = tutorialsInDynamicVector[i];
		if (s.getPresenter() == presenter && s.getTitle() == title)
			return s;
	}

	return Tutorial{};
}



bool Repository::removeTutorial(const std::string & presenter, const std::string & title)
{
	Tutorial t = this->findByPresenterAndTitle(presenter, title);
	if (t.getPresenter() == "" && t.getTitle() == "")
		return false;
	int pos = this->findPosOfTutorial(t);
	this->tutorials.deleteElem(pos);
	return true;
}

int Repository::findPosOfTutorial(const Tutorial & t)
{
	for (int i = 0; i < this->tutorials.getSize(); i++) {
		if (this->tutorials[i].getPresenter() == t.getPresenter() && this->tutorials[i].getTitle() == t.getTitle())
			return i;
	}
	return -1;
}



