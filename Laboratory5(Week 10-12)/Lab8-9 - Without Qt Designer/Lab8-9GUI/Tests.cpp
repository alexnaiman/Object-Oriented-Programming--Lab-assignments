#include "Tests.h"
#include <string>
#include <iostream>
#include <assert.h>
#include "Json.hpp"
#include <fstream>
#include "SqlRepository.h"
void testMain()
{
	testExceptions();
	testSql();
	testJson();
}

void testExceptions()
{
	std::string s = "slp";
	std::string p = "123";
	try {
		int n = Validator::strToInt(s);
	}
	catch (ValidationException& v){
		assert(std::string(v.what()) == "Cannot convert string to int");
	}

	int n = Validator::strToInt(p);
	assert(n == 123);
}

void testJson() {
	nlohmann::json j;
	std::ifstream infile("html/data.json");
	infile >> j;
	for (auto& i : j["songs"]) {
	//	std::cout << i["Title"];
	}
	infile.close();
	/*std::cout << j;
	std::cout << std::endl << j["songs"];*/
}

void testSql() {
	//SqlRepository s{"23"};

}