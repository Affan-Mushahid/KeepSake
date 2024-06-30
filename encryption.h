#pragma once
#include <iostream>
#include <string_view>
#include <pass_generator.h>

class User; // Since there is a circular dependancy between both

class Encryption {
private:
	Password_Generator m_password_generator;
	std::string m_encryption_key;

public:
	//void encrypt(std::string& item);

	std::string encrypt(std::string item);

	//void decrypt(std::string& item);

	std::string decrypt(std::string item);

	// std::string create_crypt();
  
	// void change_crypt(User& a);
};