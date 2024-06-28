#pragma once
#include <iostream>
#include <string>
#include <pass_generator.h>

class Data {
protected:
	std::string m_title;
};


class Password : protected Data {
private:
	Password_Generator* m_generator;
	std::string m_website;
	std::string m_pass;
};


class CreditCards : protected Data {
private:
	int m_card;
	int m_SSN;
	int m_expiry;
};


class IdentityCards : protected Data {
private:
	std::string full_name;
	std::string fathers_name;
	int date_of_birth;
	int date_of_expiry;
};


class Notes : protected Data {
private:
	std::string content;
};