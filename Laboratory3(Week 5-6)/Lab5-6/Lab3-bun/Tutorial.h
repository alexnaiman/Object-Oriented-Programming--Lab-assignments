#pragma once
#pragma once
#include <iostream>

class Duration
{
private:
	double minutes;
	double seconds;
public:
	// default constructor for a duration object
	Duration() : minutes(0), seconds(0) {};

	// constructor with parameters
	Duration(double min, double sec) : minutes(min), seconds(sec) {};

	//getters and setters
	double getMinutes() const { return minutes; }
	double getSeconds() const { return seconds; }
	void setMinutes(double min) { minutes = min; }
	void setSeconds(double sec) { seconds = sec; }
};

class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Duration duration;
	long numberOfLikes;
	std::string source;
	long noViews;
public:
	// default constructor for a playlist
	Tutorial();

	// constructor with parameters
	Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const double& noLikes, const std::string& source, const double& noViews = 0);

	// getters and setters to all its fields
	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	Duration getDuration() const { return duration; }
	std::string getSource() const { return source; }
	double getNoLikes() const { return numberOfLikes; }
	long getNoViews() const { return noViews; }
	// opens the chrome to see the tutorial
	void open();
	bool operator<(int value);
	void like() { numberOfLikes++; }
};
