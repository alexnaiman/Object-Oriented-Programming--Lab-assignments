#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Controller.h"
#include "TutorialModel.h"
#include "NumericFilterProxyModel.h"
#include "Iterator.h";


class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(Controller* c, QWidget *parent = Q_NULLPTR);

private:
	Ui::GUIClass ui;
	Controller* c;
	Iterator iterator;
	TutorialModel* watchlistModel;
	TutorialModel* model;
	NumericFilterProxyModel* viewsFilter;
	std::string oldFilter{ "" };
	private slots:
	void connectSignalAndSlots();
	void addTutorial();
	void initBarChart();
	void removeTutorial();
	void removeFromWatchlist();
	void setViewsFilterValue();

	void configIterator();
	void updateCurrentTutorial();
	void addToWatchlist();
	void openCurrentTutorial();
	void next();
	void likeCurrentTutorial();
	void filterByViews();
	void undo();
	void redo();
	void undoWatchlist();
	void redoWatchlist();
};
