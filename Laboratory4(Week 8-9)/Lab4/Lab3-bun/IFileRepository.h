#pragma once
#include "Repo.h"
// Our interface for creating repos that read and write to a specific type
class IFileRepository : public Repository {
protected:
	std::string source;
	// pure abstract methods used for writing and reading a file
	virtual void repoFromFile() = 0; 
	virtual void repoToFile() = 0; 

public:

	IFileRepository(const std::string& source) : Repository(), source(source) {}

	IFileRepository(const IFileRepository& fl) : Repository(fl), source(fl.source) {}

	virtual	~IFileRepository() = default;

	virtual void display() = 0;

};