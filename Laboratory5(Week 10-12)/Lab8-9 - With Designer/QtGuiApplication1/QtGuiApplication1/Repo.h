#pragma once
#include "DynamicVector.h"
#include "Tutorial.h"
#include <vector>
#include <exception>
#include "Validator.h"

class Repository
{
protected:
	std::vector<Tutorial>* tutorials;

public:
	/*
	Default constructutor.
	Initializes an object of type repository.
	*/
	Repository();
	~Repository();
	Repository(const Repository& r);
	Repository& operator=(const Repository& t);
	void updateTutorial(Tutorial t, std::string presenter, std::string title);
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
	Out: vector<Tutorial>
	*/
	std::vector<Tutorial>* getTutorials() { return tutorials; }

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

class RepositoryException : public ValidationException {
public:
	RepositoryException(std::string message): ValidationException(message){}
};