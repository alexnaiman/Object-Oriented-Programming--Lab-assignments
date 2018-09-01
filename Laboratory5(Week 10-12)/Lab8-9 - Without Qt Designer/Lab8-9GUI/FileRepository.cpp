//#include "FileRepository.h"
//#include <fstream>
//
//void FileRepository::repoFromFile()
//{
//	std::ifstream infile(source);
//	Tutorial t;
//	while (infile >> t)
//	{
//		this->addTutorial(t);
//	}
//	infile.close();
//}
//
////FileRepository::~FileRepository()
////{
////	this->repoToFile();
////}
//
//void FileRepository::repoToFile()
//{
//	std::ofstream outFile(source);
//	std::vector<Tutorial>s = this->getTutorials();
//	for (auto&it : s)
//		outFile << it << std::endl;
//}
//
