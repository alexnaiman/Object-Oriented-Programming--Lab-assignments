#include "CSVRepository.h"
#include <fstream>
#include <stdlib.h>

void CSVRepository::repoFromFile()
{
	std::ifstream infile(source);
	if (!infile.is_open())
		throw RepositoryException("Cannot open file: " + source);
	Tutorial t;
	while (infile >> t)
	{
		this->addTutorial(t);
	}
	infile.close();
}

//CSVRepository::~CSVRepository()
//{
//	std::cout << "1";
//	this->repoToFile();
//}

void CSVRepository::repoToFile()
{
	std::ofstream outFile(source);
	std::vector<Tutorial>* s = this->getTutorials();
	for (auto&it : *s)
		outFile << it << std::endl;
	outFile.close();
}

CSVRepository::CSVRepository(const std::string & source) : IFileRepository(source) {
	this->repoFromFile();
}

CSVRepository::~CSVRepository()
{
	this->repoToFile();
}

void CSVRepository::display()
{
	std::string s = "notepad \"" + source + "\"";
	system(s.c_str());
}

