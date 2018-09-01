#pragma once
#include <exception>
#include <string>
class Validator {
public:
	static bool canStrToInt(const std::string& s);
	static bool isStrEmpty(const std::string& s); 

	static int strToInt(const std::string& s);
	static std::string checkString(const std::string& s);
};

class ValidationException : public std::exception {
private:
	std::string message;
public:
	ValidationException(std::string message) : message(message) {}

	const char* what()
	{
		return message.c_str();
	}
};
