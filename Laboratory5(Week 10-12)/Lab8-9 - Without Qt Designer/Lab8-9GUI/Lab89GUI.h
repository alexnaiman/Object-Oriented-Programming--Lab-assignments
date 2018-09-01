#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Lab89GUI.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>

#include "Controller.h"
#include "SqlRepository.h"
#include <vector>
#include <algorithm>
#include "Tutorial.h"
#include "Utils.h"

class Lab89GUI : public QWidget
{
	Q_OBJECT

public:
	Lab89GUI(Controller* c, QWidget* parent = 0);
	~Lab89GUI();
private:
	// lists
	QListWidget * tutorialListWidget;
	QListWidget *watchList;
	
	// form		
	QLineEdit* titleInput;
	QLineEdit* presenterInput;
	QLineEdit* noLikesInput;
	QLineEdit* durationInput;
	QLineEdit* sourceInput;
	QLineEdit* noViewsInput;
	
	// buttons
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* moveOneButton;
	QPushButton* moveAllButton;
	
	Controller* ctrl;

	std::vector<Tutorial> tutorialsListVector;
	void init();
	void populate();
	int getSelecteTutorialIndex();
	void populateWL();
	private slots:
	void connectSignalsAndSlots();
	void moveTutorialToWatchlist();
	void deleteTutorial();
	void moveAllTutorials();
	void addNewTutorial();
};
