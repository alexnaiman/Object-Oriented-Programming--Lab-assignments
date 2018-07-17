#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}
	//~UI();
	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printWatchListMenu();

	void addTutorialToRepo();
	void deleteTutorialFromRepo();
	void updateTutorialFromRepo();
	void displayAllTutorialsRepo();
	void printTutorial(const Tutorial&t, bool flag=true);
	void addTutorialToWatchlist();
	void viewWatchlist();
	//void addTutorialToPlaylist();
	//void addAllTutorialsByArtistToPlaylist();
};

