#pragma once
#include "IFileRepository.h"
#include "Iterator.h"
class Controller
{
private:
	IFileRepository* repo;
	IFileRepository* watchlist;
	Iterator tutoritalsIter;
public:
	bool serializable;

	Controller(IFileRepository* r, IFileRepository* w) : tutoritalsIter() {
		repo = r;
		watchlist = w;
	};
	Controller(const Controller& c);
	~Controller();
	Controller& operator= (const Controller& c);
	IFileRepository* getRepo() const { return repo; }
	Repository* getWatchlist() const { return watchlist; }
	// Adds a tutorial with the given data to the tutorial repository.
	/*
		In:
			presenter: string
			title: string
			minutes: double;
			seconds: double;
			noLikes: double;
			source: string
		Out:
			true if tutorial was added succesfully
			false otherwise
	*/
	bool addTutorialToRepository(Tutorial& t);

	/*
		Removes a tutorial from the repository
		In:
		presenter: string
		title: string
		Out:
		true if tutorial was removed succesfully
		false otherwise
	*/
	bool removeTutorialFromRepository(const std::string& presenter, const std::string& title);


	/*
		Updates a tutorial from the repository
		In:
		presenter: string
		title: string;
		minutes: double;
		seconds: double;
		noLikes: double;
		source: string;
		newName: string;
		newTitle: string;
		Out:
		true if tutorial was updated succesfully
		false otherwise
	*/
	bool updateTutorialFromRepository(const std::string& presenter, const std::string& title, Tutorial& t);

	/*
	Adds a given tutorial to the current playlist.
	Input: tutorial - Tutorial, the tutorial must belong to the repository.
	Output: the tutorial is added to the playlist.
	*/
	void addTutorialToWatchlist(const Tutorial& tutorial);
	/*
	Configures the iterator dynamic array
	Input: presenter - string - the presenter which owns the tutorials we want to iterate through
	output: the dynamic vector from the iterate contains either the whole list of tutorials or only the ones owned by the given prsenter
	*/
	void configIterator(const std::string & presenter);
	/*
	Returns the current tutorial from the iterator
	*/
	Tutorial getCurrentTutorial();
	/*
	Start and plays the first tutorial from the iterator
	*/
	void startIteration();
	/*
	Deletes the given tutorial from the watchlist
	Input: tutorial - Tutorial - the tutorial we want to delete
	output: bool - true if the tutorial was deleted
	*/
	bool deleteTutorialFromWatchlist(const Tutorial & tutorial);
	/*
	Plays the next tutorial from the iterator
	*/
	void next();

	/*
	Increases the number of likes of the current tutorial
	Output: true if it "liked" the tutorial successfully
	*/
	bool likeTutorial();
	void toFile();
	std::vector<Tutorial> filter(int value);
	void display();
};

