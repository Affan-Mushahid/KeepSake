#pragma once
#include <iostream>
#include <string_view>
#include <pass_generator.h>


class Encryption {
private:
	std::string m_encryption_key;

	std::string lower_case;

	std::string upper_case;

	std::string generate_key();

	void setup_crypt();
public:
	Encryption();

	std::string encrypt(std::string item);

	std::string decrypt(std::string item);

	
};