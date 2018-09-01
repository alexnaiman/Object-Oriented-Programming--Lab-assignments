#include "Lab89GUI.h"
#include "Utils.h"
#include <sstream>
#include "Validator.h"


Lab89GUI::Lab89GUI(Controller* c, QWidget* parent) : ctrl(c), QWidget{ parent }
{
	this->init();
	this->tutorialsListVector = *this->ctrl->getRepo()->getTutorials();
	this->populate();
}

Lab89GUI::~Lab89GUI()
{
	delete ctrl;
}

void Lab89GUI::init()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Left side widget containing the repository list, the form for editing/adding tutorials and 
	// the corresponding buttons
	QWidget* leftW = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftW };

	// List
	this->tutorialListWidget = new QListWidget{};
	// Set the selection model
	this->tutorialListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	// Tutorial form
	QWidget* tutorialDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ tutorialDataWidget };
	this->presenterInput = new QLineEdit{};
	this->sourceInput = new QLineEdit{};
	this->noLikesInput = new QLineEdit{};
	this->titleInput = new QLineEdit{};
	this->noViewsInput = new QLineEdit{};
	this->durationInput = new QLineEdit{};
	formLayout->addRow("&Presenter:", presenterInput);
	formLayout->addRow("&Link:", sourceInput);
	formLayout->addRow("&Likes:", noLikesInput);
	formLayout->addRow("&Title:", titleInput);
	formLayout->addRow("&Views:", noViewsInput);
	formLayout->addRow("&Duration:", durationInput);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add a tutorial");
	this->deleteButton = new QPushButton("Delete a tutorial");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "Tutorials" });
	leftSide->addWidget(tutorialListWidget);
	leftSide->addWidget(tutorialDataWidget);
	leftSide->addWidget(buttonsWidget);

	// middle side widget:
	// - move all tutorials to watchlist
	// - move one tutorial 
	QWidget* middleW = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleW };
	this->moveOneButton = new QPushButton{ ">" };
	this->moveAllButton = new QPushButton{ ">>" };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(moveOneButton);
	vLayoutUpperPart->addWidget(moveAllButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right sidw widget - the watchlist
	QWidget* rightW = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightW };

	// playlist
	watchList = new QListWidget{};

	// buttons
	//	- play button
	//  - next button
	QWidget* watchlistButtonsWidget = new QWidget{};
	QHBoxLayout* watchlistButtonsLayout = new QHBoxLayout{ watchlistButtonsWidget };
	watchlistButtonsLayout->addWidget(new QPushButton{ "&Play" });
	watchlistButtonsLayout->addWidget(new QPushButton{ "&Next" });

	// create the right widget
	rightSide->addWidget(new QLabel{ "Watchlist" });
	rightSide->addWidget(watchList);
	rightSide->addWidget(watchlistButtonsWidget);

	// compose the main layout with the three created widgets
	layout->addWidget(leftW);
	layout->addWidget(middleW);
	layout->addWidget(rightW);

	// connect the signals and slots
	this->connectSignalsAndSlots();
}

void Lab89GUI::populate()
{
	// empty the list
	if (tutorialListWidget->count() != 0)
		tutorialListWidget->clear();

	// add the strings as items to the list
	for (auto t : tutorialsListVector) {
		QString listItem = QString::fromStdString(t.toString());
		QListWidgetItem *listItemWidget = new QListWidgetItem(listItem);
		this->tutorialListWidget->addItem(listItemWidget);
	}

	// set the first element to be selected
	if (tutorialsListVector.size() > 0)
		tutorialListWidget->setCurrentRow(0);
}

int Lab89GUI::getSelecteTutorialIndex()
{
	if (tutorialListWidget->count() == 0)
		return -1;
	QModelIndexList indexList = this->tutorialListWidget->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		presenterInput->clear();
		titleInput->clear();
		noLikesInput->clear();
		durationInput->clear();
		sourceInput->clear();
		noViewsInput->clear();
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void Lab89GUI::populateWL()
{
	// empty the list
	if (watchList->count() == 0)
		watchList->clear();

	for (auto t : *(this->ctrl->getWatchlist()->getTutorials()))
	{
		QString itemInList = QString::fromStdString(t.getTitle() + " - " + t.getPresenter());
		this->watchList->addItem(itemInList);
	}
}

void Lab89GUI::addNewTutorial()
{
	std::string title = titleInput->text().toStdString();
	std::string presenter = presenterInput->text().toStdString();
	int noLikes = std::stoi(noLikesInput->text().toStdString());
	std::string duration = durationInput->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must be formated as \"M:S\"!");
		return;
	}
	std::string source = sourceInput->text().toStdString();
	int noViews = std::stoi(this->noViewsInput->text().toStdString());
	std::string tutorialString = presenter + ',' + title + ',' + std::to_string(noLikes) + ',' + std::to_string(noViews) + ',' + durationTokens[0] + "," + durationTokens[1] + ',' + source;

	std::stringstream stream{tutorialString};
	try
	{
		Tutorial t;
		stream >> t;
		ctrl->addTutorialToRepository(t);
		// refresh the list
		tutorialsListVector = *this->ctrl->getRepo()->getTutorials();
		this->populate();
	}
	catch (ValidationException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what();
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot add element! Tutorial already existing");
	}
}

void Lab89GUI::deleteTutorial()
{

}

void Lab89GUI::moveAllTutorials()
{
}

void Lab89GUI::moveTutorialToWatchlist()
{
}

// connects all the components to their callbacks
void Lab89GUI::connectSignalsAndSlots() {
	// connect repository widget and add a callback that modifies the selection of the tutorials
	QObject::connect(tutorialListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	// add button
	// connect the addButton to the callback that is called when the clicked() event happened
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewTutorial()));

}
