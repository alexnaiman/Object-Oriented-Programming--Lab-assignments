#pragma once
#include "Repo.h"

class IFileRepository : public Repository {
protected:
	std::string source;

	virtual void repoFromFile() = 0; //{ std::cout << "fromFile" << std::endl; };
	virtual void repoToFile() = 0; //{ std::cout << "toFile" << std::endl; };

public:

	IFileRepository(const std::string& source) : Repository(), source(source) {}

	IFileRepository(const IFileRepository& fl) : Repository(fl), source(fl.source) {}

	virtual	~IFileRepository() = default;

	virtual void display() = 0;

};