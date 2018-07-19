#include "UI.h"
#include <string>
#include <crtdbg.h>
#include "Validator.h"

//#include <boost/regex.hpp>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "Masteer C++" << endl;
	cout << "1 - Manage Tutorials repository." << endl;
	cout << "2 - Manage watchlist." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add tutorial." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Delete tutorial" << endl;
	cout << "\t 4 - Update tutorial" << endl;
	cout << "\t 5 - Filter by no. views" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printWatchListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add tutorial to watchlist" << endl;
	cout << "\t 2 - View watchlist" << endl;
	cout << "\t 3 - Delete tutorial from watchlist." << endl;
	cout << "\t 4 - Like this tutorial." << endl;
	cout << "\t 5 - Next" << endl;
	cout << "\t 6 - Display" << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::addTutorialToRepo()
{
	Tutorial t;
	cout << "Enter the tutorial data(fields separated by \",\")"<<endl;

	try {
		cin >> t;
	if (this->ctrl->addTutorialToRepository(t))
		cout << "Tutorial added succesfully!" << endl;
	else
		cout << "Cannot add tutorial";
	}
	catch (RepositoryException& v){
		cout << v.what() << endl;
	}
	catch (ValidationException& v) {
		cout << v.what() << endl;
	}
}

void UI::deleteTutorialFromRepo()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	try {
		if (this->ctrl->removeTutorialFromRepository(presenter, title))
			cout << "The tutorial was removed successfully!" << endl;
	}
	catch (RepositoryException& r) {
		cout << r.what() << endl;
	}
}

void UI::updateTutorialFromRepo()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the new updated tutorial\n";
	Tutorial t;
	cin >> t;
	try {
	if (this->ctrl->updateTutorialFromRepository(presenter, title, t))
		cout << "Tutorial updated successfully!" << endl;
	else
		cout << "An error occured: cannot find tutorial/the new tutorial presenter and name are already added" << endl;
	}
	catch (RepositoryException& v) {
		cout << v.what() << endl;
	}
	catch (ValidationException& v) {
		cout << v.what() << endl;
	}



}

void UI::displayAllTutorialsRepo()
{
	std::vector<Tutorial>* v = this->ctrl->getRepo()->getTutorials();
	if (v->size() == 0)
	{
		cout << "There are no tutorials in the repository." << endl;
		return;
	}

	int i = 1;
	for (auto& it : *v)
	{
		cout << i << ". ";
		this->printTutorial(it, true);
		i++;
	}
}
void UI::printTutorial(const Tutorial& t, bool flag) {
	Duration d = t.getDuration();
	cout << "\tPresenter: " << t.getPresenter() << endl;
	cout << "\tTitle: " << t.getTitle() << endl;
	flag && cout << "\tNumber of likes: " << t.getNoLikes() << endl;
	cout << "\tDuration: " << d.getMinutes() << ":" << d.getSeconds() << endl;
	cout << "\tNoViews: " << t.getNoViews() << endl;
	cout << endl;
}

void UI::addTutorialToWatchlist()
{
	try {
		this->ctrl->addTutorialToWatchlist(this->ctrl->getCurrentTutorial());
	}
	catch (RepositoryException& v) {
		cout << "Tutorial already added to watchlist"<<endl;
	}
}

void UI::viewWatchlist()
{
	std::vector<Tutorial>* v = this->ctrl->getWatchlist()->getTutorials();
	if (v->size() == 0)
	{
		cout << "There are no tutorials in the watchlist." << endl;
		return;
	}
	int i = 0;
	for (auto& it : *v)
	{
		cout << i << ". ";
		this->printTutorial(it, false);
		i++;

	}
}


UI::UI(Controller * c)
{
	ctrl = c;
}

UI::~UI()
{
	delete ctrl;
}

void UI::run()
{
	cin.ignore();
	while (true)
	{
		int command{ 0 };
		std::string comm;
		UI::printMenu();
		cout << "Input the command: ";
		getline(cin, comm);
		try {
			command = Validator::strToInt(comm);
		}
		catch (ValidationException& v) {
			cout << "Command error: " << v.what();
			continue;
		}
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				std::string comm;
				cout << "Input the command: ";
				getline(cin, comm);
				try {
					commandRepo = Validator::strToInt(comm);
				}
				catch (ValidationException& v) {
					cout << "Command error: " << v.what();
				}

				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addTutorialToRepo();
					break;
				case 2:
					this->displayAllTutorialsRepo();
					break;
				case 3:
					this->deleteTutorialFromRepo();
					break;
				case 4:
					this->updateTutorialFromRepo();
					break;
				case 5:
					string value;
					cout << "Please give number: ";
					try {
						cin >> value;
						int val = Validator::strToInt(value);
						std::vector<Tutorial> v = this->ctrl->filter(val);
						cout << "The tutorials are: " << endl;
						if (v.size() == 0) cout << "    Oops...no tutorial in here" << endl;
						else {
							for (auto& it : v) {
								printTutorial(it);
							}

						}
					}
					catch (ValidationException& v) {
						cout << "Command error: " << v.what();
					}
					cin.ignore();
					break;
				}
			}
		}

		// watchlist management
		if (command == 2)
		{
			std::string presenter{};
			cout << "What presenter would you like to watch?";
			getline(cin, presenter);
			this->ctrl->configIterator(presenter);
				if (this->ctrl->getCurrentTutorial().getPresenter() != "")
				{
					this->ctrl->startIteration();
					printTutorial(this->ctrl->getCurrentTutorial(), false);
				}
				else {
					cout << "Sorry no tutorial with that presenter exists" << endl;
					continue;
				}
			cout << endl;
			while (true)
			{
				UI::printWatchListMenu();
				int commandPlaylist{ 0 };
				std::string comm;
				cout << "Input the command: ";
				getline(cin, comm);
				try {
					commandPlaylist = Validator::strToInt(comm);
				}
				catch (ValidationException& v) {
					cout << "Command error: " << v.what();
				}
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist)
				{
				case 1:
					this->addTutorialToWatchlist();
					break;
				case 2:
					this->viewWatchlist();
					break;
				case 3:
				{
					try {

					if (this->ctrl->deleteTutorialFromWatchlist(this->ctrl->getCurrentTutorial()))
						cout << "Tutorial deleted from watchlist" << endl;
					else
						cout << "Tutorial is not in playlist" << endl;
					break;
					}
					catch (RepositoryException& v) {
						cout << "The tutorial is not in playlist" << endl;
					}
				}
				case 5:
				{
					this->ctrl->next();
					this->printTutorial(this->ctrl->getCurrentTutorial(), false);
					break;
				}
				case 4: {
					this->ctrl->likeTutorial();
					break;
				}
				case 6: {
					this->ctrl->display();
					break;
				}
				}
			}
		}
	}
}