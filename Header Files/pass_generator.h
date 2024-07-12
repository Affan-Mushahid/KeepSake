#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Password_Generator {
private:
	std::string lowercase_letters;
	std::string uppercase_letters;
	std::string digits;
	std::string symbols;

public:
	Password_Generator();

	std::string generate(int size = 8, bool include_symbols = true);
};