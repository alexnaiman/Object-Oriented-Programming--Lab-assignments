#include "Validator.h"
#include <algorithm>
#include <cctype>
#include <string>
bool Validator::canStrToInt(const std::string & s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

bool Validator::isStrEmpty(const std::string& s)
{
	return s.size() == 0;
}

int Validator::strToInt(const std::string & s)
{
	if (Validator::canStrToInt(s))
		return std::stoi(s);
	else
		throw ValidationException("Cannot convert string to int");
}

std::string Validator::checkString(const std::string & s)
{
	if (!Validator::isStrEmpty(s))
		return s;
	throw ValidationException("String cannot be empty");
}

