#include "UI.h"
#include <string>

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
	cout << "\t 0 - Back." << endl;
}

void UI::addTutorialToRepo()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	double minutes = 0, seconds = 0, noLikes, noViews;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "\tNumber of likes: ";
	cin >> noLikes;
	cin.ignore();
	cout << "\tNumber of views: ";
	cin >> noViews;
	cin.ignore();
	cout << "Link to the tutorial: ";
	std::string link;
	getline(cin, link);

	if (this->ctrl.addTutorialToRepository(presenter, title, minutes, seconds, noLikes, link, noViews))
		cout << "Tutorial added succesfully!" << endl;
	else
		cout << "Cannot add tutorial";
}

void UI::deleteTutorialFromRepo()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	if (this->ctrl.removeTutorialFromRepository(presenter, title))
		cout << "The tutorial was removed successfully!";
	else
		cout << "Cannot find the tutorial" << endl;
}

void UI::updateTutorialFromRepo()
{
	cout << "Enter the presenter: ";
	std::string presenter;
	getline(cin, presenter);
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the new presenter: ";
	std::string newPresenter;
	getline(cin, newPresenter);
	cout << "Enter the new title: ";
	std::string newTitle;
	getline(cin, newTitle);
	double minutes = 0, seconds = 0, noLikes;
	cout << "Enter the duration: " << endl;
	cout << "\tMinutes: ";
	cin >> minutes;
	cin.ignore();
	cout << "\tSeconds: ";
	cin >> seconds;
	cin.ignore();
	cout << "\tNumber of likes: ";
	cin >> noLikes;
	cin.ignore();
	cout << "Link to the tutorial: ";
	std::string link;
	getline(cin, link);


	if (this->ctrl.updateTutorialFromRepository(presenter, title, minutes, seconds, noLikes, link, newPresenter, newTitle))
		cout << "Tutorial updated successfully!" << endl;
	else
		cout << "An error occured: cannot find tutorial/the new tutorial presenter and name are already added" << endl;



}

void UI::displayAllTutorialsRepo()
{
	DynamicVector<Tutorial> v = this->ctrl.getRepo().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no tutorials in the repository." << endl;
		return;
	}


	for (int i = 0; i < v.getSize(); i++)
	{
		cout << i << ". ";
		Tutorial t = tutorials[i];
		this->printTutorial(t,true);

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
	this->ctrl.addTutorialToWatchlist(this->ctrl.getCurrentTutorial());
}

void UI::viewWatchlist()
{
	DynamicVector<Tutorial> v = this->ctrl.getWatchlist().getTutorials();
	Tutorial* tutorials = v.getAllElems();
	if (tutorials == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no tutorials in the watchlist." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial t = tutorials[i];
		cout << i << ". ";
		this->printTutorial(t, false);

	}
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
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
					double value;
					cout << "Please give number: ";
					cin >> value;
					DynamicVector<Tutorial> v = this->ctrl.filter(value);
					for (int i = 0; i < v.getSize(); i++) {
						printTutorial(v[i]);
					}
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
			this->ctrl.configIterator(presenter);
			if (this->ctrl.getCurrentTutorial().getPresenter() != "")
			{
				this->ctrl.startIteration();
				printTutorial(this->ctrl.getCurrentTutorial(), false);
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
				
				cout << "Input the command: ";
				cin >> commandPlaylist;
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
					if (this->ctrl.deleteTutorialFromWatchlist(this->ctrl.getCurrentTutorial()))
						cout << "Tutorial deleted from watchlist" << endl;
					else
						cout << "Tutorial is not in playlist" << endl;
					break;
				}
				case 5:
				{
					this->ctrl.next();
					this->printTutorial(this->ctrl.getCurrentTutorial(),false);
					break;
				}
				case 4: {
					this->ctrl.likeTutorial();
					break;
				}
				}
			}
		}
	}
}