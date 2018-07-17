#pragma once
#include "DynamicVector.h"
#include "Tutorial.h"

class Repository
{
private:
	DynamicVector<Tutorial> tutorials;

public:
	/*
	Default constructutor.
	Initializes an object of type repository.
	*/
	Repository() {}
	//~Repository();

	/*
	Adds a tutorial to the repository.
	Input: t - tutorial.
	Output: bool - true the tutorial is added to the repository, false otherwise.
	*/
	bool addTutorial(const Tutorial& t);

	/*
	Finds a tutorial, by presenter and title.
	Input: presenter, title - string
	Output: the tutorial that was found, or an "empty" tutorial (all fields empty and duration 0), if nothing was found.
	*/
	Tutorial findByPresenterAndTitle(const std::string& presenter, const std::string& title);

	/*
	Returns all the tutorials from the repository.
	Input: none.
	Out: DynamicVector<Tutorial>
	*/
	DynamicVector<Tutorial> getTutorials() { return tutorials; }

	/*
	Removes a tutorial from repository by presenter and title.
	Input: presenter, title - string
	Output: bool - true the tutorial is removed from the repository, false otherwise.
	*/
	bool removeTutorial(const std::string& presenter, const std::string& title);
	/*
	Finds a tutorial
	Input: presenter, title - string
	Output: its position in the dynamic vector
	*/
	int findPosOfTutorial(const Tutorial& t);
};