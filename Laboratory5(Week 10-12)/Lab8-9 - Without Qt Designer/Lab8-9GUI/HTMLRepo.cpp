#include "HTMLRepo.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "Json.hpp"
#include <Windows.h>
#include <shellapi.h>

void HTMLRepository::repoFromFile()
{
	nlohmann::json j;
	std::ifstream infile(source);
	if (!infile.is_open())
		throw RepositoryException("Cannot open file: " + source);
	infile >> j;
	for (auto& i : j["tutorials"]) {
		std::string duration = i["Duration"];
		std::string minutes(duration.begin(), std::find(duration.begin(), duration.end(), ':'));
		std::string seconds(std::find(duration.begin(), duration.end(), ':') + 1, duration.end());
		this->addTutorial(TutorialFactory::MakeTutorial(i["Title"], i["Presenter"], minutes, seconds, i["No. likes"], i["Source"], i["No. views"]));
	}
	infile.close();
}

void HTMLRepository::repoToFile()
{
	std::ofstream outFile(source);
	nlohmann::json j;
	if (tutorials->size() == 0) {
		j["tutorials"]=R"([])"_json;
	}
	for (auto& it : *(this->tutorials)) {
		j["tutorials"].push_back({ {"Title",it.getTitle()},{"Presenter",it.getPresenter()},{"Duration", std::to_string(it.getDuration().getMinutes()) + ":" + std::to_string(it.getDuration().getSeconds())}, {"No. likes",std::to_string(it.getNoLikes())},{"No. views",std::to_string(it.getNoViews())},{"Source",it.getSource() } });
	}
	
	outFile << std::setw(4) << j << std::endl;
	outFile.close();
}

HTMLRepository::HTMLRepository(const std::string & source, const std::string& site) : IFileRepository(source), site(site) {
	std::cout << site;

	this->repoFromFile();
}

HTMLRepository::~HTMLRepository()
{
	this->repoToFile();
}

void HTMLRepository::display()
{
	std::string htmlJumper = site;
	ShellExecuteA(NULL, NULL, "chrome.exe", htmlJumper.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecute(NULL, "edg.exe", site.c_str(), NULL, NULL, SW_SHOWMAXIMIZED);
	//system(htmlJumper.c_str());

}

