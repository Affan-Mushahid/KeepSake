#pragma once
#include <iostream>
#include <string_view>

class User; // Since there is a circular dependancy between both

class Encryption {
public:
	void encrypt(std::string_view encryption_key, std::string& item);

	void decrypt(std::string_view encryption_key, std::string& item);

	std::string create_crypt();
  
	void change_crypt(User& a);
};