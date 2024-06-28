#pragma once
#include <iostream>
#include <string>

class Password_Generator {
private:
	std::string lowercase_letters;
	std::string uppercase_letters;
	std::string digits;
	std::string symbols;

public:
	std::string generate(int size = 8, int letters_limit = 8, int digits_limit = 4, int symbols_limit = 2, bool include_symbols = true);
};