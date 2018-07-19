#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include "Validator.h"
#include "Utils.h"
#include <vector>

using namespace std;

Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), numberOfLikes(0), source(""), noViews(0) {}


Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& noLikes, const std::string& source, const int & noViews) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->numberOfLikes = noLikes;
	this->source = source;
	this->noViews = noViews;
}

bool Tutorial::operator==(const Tutorial & t)
{
	return this->getPresenter() == t.getPresenter() && this->getTitle() == t.getTitle();
}

void Tutorial::open() {
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool Tutorial::operator<(int value)
{
	return this->noViews < value;
}

std::string Tutorial::toHtml()
{
	std::string s="";
	s += "{";
	s += "\"Title\":\"" + title + "\",";
	s += "\"Presenter\":\"" + presenter + "\",";
	s += "\"Duration\":\"" + std::to_string(duration.getMinutes()) + ":" + std::to_string(duration.getSeconds()) + "\",";
	s += "\"No. Likes\":\"" + std::to_string(numberOfLikes) + "\",";
	s += "\"No. Views\":\"" + std::to_string(noViews) + "\",";
	s += "\"Source\":\"" + source + "\"";
	s += "}";
	return s;
}

std::ostream & operator<<(std::ostream & out, const Tutorial & t)
{
	out << t.getPresenter().c_str() << "," << t.getTitle().c_str() << "," << t.getNoLikes() << "," << t.getNoViews() << "," << t.getDuration().getMinutes() << "," << t.getDuration().getSeconds() << "," << t.getSource().c_str();
	return out;
}

std::istream & operator >> (std::istream & in, Tutorial & t)
{
	string line;
	getline(in, line);
	if (line.size() == 0)
		return in;
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 7) // make sure all the song data was valid
		throw ValidationException("Sorry! the number of fields is not ok!");
	t = TutorialFactory::MakeTutorial(trim(tokens[1]), trim(tokens[0]), trim(tokens[4]), trim(tokens[5]), trim(tokens[3]), trim(tokens[6]), trim(tokens[2]));
	
	return in;
}

Tutorial TutorialFactory::MakeTutorial(const std::string & title, const std::string & presenter, const std::string & m, const std::string & s, const std::string &  noLikes, const std::string & source, const std::string & noViews)
{
	std::string errors = "";
	std::string titleS = "";
	std::string presenterS = "", sourceS = "";
	int minutes = 0, seconds = 0, noLikesS = 0, noViewsS = 0;
	try {
		titleS = Validator::checkString(title);
	}
	catch (ValidationException& v) {
		errors += "\nTitle Error: " + std::string(v.what());
	}
	try {
		presenterS = Validator::checkString(presenter);
	}
	catch (ValidationException& v) {
		errors += "\nPresenter Error: " + std::string(v.what());
	}
	try {
		sourceS = Validator::checkString(source);
	}
	catch (ValidationException& v) {
		errors += "\nSource Error: " + std::string(v.what());
	}

	try {
		minutes = Validator::strToInt(m);
	}
	catch (ValidationException& v) {
		errors += "\nMinutes Error: " + std::string(v.what());
	}

	try {
		seconds = Validator::strToInt(s);
	}
	catch (ValidationException& v) {
		errors += "\nSeconds Error: " + std::string(v.what());
	}

	try {
		noLikesS = Validator::strToInt(noLikes);
	}
	catch (ValidationException& v) {
		errors += "\nNo. Likes Error: " + std::string(v.what());
	}
	try {
		noViewsS = Validator::strToInt(noViews);
	}
	catch (ValidationException& v) {
		errors += "\nNo. Views Error: " + std::string(v.what());
	}

	if (errors.size() != 0)
		throw ValidationException(errors);
	return Tutorial(titleS, presenterS, Duration(minutes, seconds), noLikesS, sourceS, noViewsS);

}
