#pragma once
#include <exception>
#include <string>
class Validator {
public:
	/* 
		Checks if it can convert a string to int
		in: s - string
		out: bool - True if it can be converted, false otherwise
	*/
	static bool canStrToInt(const std::string& s);

	/*
		Checks if a string is empty or not 
		in: s - string
		out: bool - True if it is empty, false otherwise
	*/
	static bool isStrEmpty(const std::string& s); 

	/*
		Convert a string to int
		in: s - string
		out: int - the string converted int
		throws: ValidationException
	*/
	static int strToInt(const std::string& s);
	static std::string checkString(const std::string& s);
};
// Custom Validation Exception class
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
