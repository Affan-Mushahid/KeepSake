#pragma once
#include <iostream>
#include <string_view>


class Encryption {
public:
	void encrypt(std::string_view encryption_key, std::string& item);

	void decrypt(std::string_view encryption_key, std::string& item);

	void change_crypt(std::string& encryption_key);
};