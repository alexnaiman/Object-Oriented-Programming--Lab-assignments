#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>

Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), numberOfLikes(0), source(""), noViews(0) {}


Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const double& noLikes, const std::string& source, const double & noViews) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->numberOfLikes = noLikes;
	this->source = source;
	this->noViews = noViews;
}

void Tutorial::open() {
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool Tutorial::operator<(int value)
{
	return this->noViews < value;
}
