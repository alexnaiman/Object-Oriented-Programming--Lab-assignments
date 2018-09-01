#pragma once
#include <iostream>

class Duration
{
private:
	int minutes;
	int seconds;
public:
	Duration() : minutes(0), seconds(0) {};
	Duration(int min, int sec) : minutes(min), seconds(sec) {};

	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }
	void setMinutes(int min) { minutes = min; }
	void setSeconds(int sec) { seconds = sec; }
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
	Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& noLikes, const std::string& source, const int& noViews = 0);

	// getters and setters to all its fields
	std::string getTitle() const { return title; }
	void setTitle(std::string _title) { title = _title; }

	std::string getPresenter() const { return presenter; }
	std::string setPresenter(std::string _presenter) {  presenter=_presenter; }

	Duration getDuration() const { return duration; }
	void setDuration(Duration _d) { duration = _d; }

	std::string getSource() const { return source; }
	void setSource(std::string _source) { source = _source; }

	int getNoLikes() const { return numberOfLikes; }
	void setLikes(int likes) { numberOfLikes = likes; }
	
	long getNoViews() const { return noViews; }
	void setViews(int views) { noViews = views; }
	// opens the chrome to see the tutorial
	void open();
	void like() { numberOfLikes++; }

	// operators overloading
	bool operator==(const Tutorial& t);
	bool operator<(int value);
	friend std::ostream & operator << (std::ostream &out, const Tutorial &t);
	friend std::istream & operator >> (std::istream &in, Tutorial &t);
	std::string toHtml();
};

class TutorialFactory {
private:
public:
	static Tutorial MakeTutorial(const std::string & title, const std::string & presenter, const std::string & m, const std::string & s, const std::string &  noLikes, const std::string & source, const std::string & noViews = "0");
};