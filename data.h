#pragma once
#include <iostream>
#include <string>
#include <pass_generator.h>

class Data {
protected:
	std::string m_title;
};


class Password : public Data {
private:
	Password_Generator* m_generator;
	std::string m_website;
	std::string m_pass;

public:
	Password(std::string title, std::string website, std::string pass);

};


class CreditCards : public Data {
private:
	int m_card;
	int m_SSN;
	int m_expiry;

public:
	CreditCards(std::string title, int card, int ssn, int expiry);
};


class Date {
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date(int day, int month, int year);

	int day();
	int month();
	int year();
};

class IdentityCards : public Data {
private:
	std::string m_full_name;
	std::string m_fathers_name;
	Date m_date_of_birth;
	Date m_date_of_issue;
	Date m_date_of_expiry;
};


class Notes : public Data {
private:
	std::string content;

};