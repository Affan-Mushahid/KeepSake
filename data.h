#pragma once
#include <iostream>
#include <string>
#include <pass_generator.h>

class Data {
protected:
	std::string m_title;
	std::string m_data_type;

public:
	Data(std::string title, std::string data_type);

	virtual std::string data_type();
	virtual std::string title();
};


class Password : public Data {
private:
	Password_Generator* m_generator;
	std::string m_website;
	std::string m_pass;

public:
	Password(std::string title, std::string website, std::string pass);
	std::string website();
	std::string password();
};


class CreditCards : public Data {
private:
	int m_card;
	int m_SSN;
	int m_expiry;

public:
	CreditCards(std::string title, int card, int ssn, int expiry);

	int card();

	int ssn();

	int expiry();
};


class Date {
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date(int day, int month, int year);

	Date(Date& D);

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

public:
	IdentityCards(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry);

	std::string full_name();

	std::string fathers_name();

	std::string birth_text();

	std::string issue_text();

	std::string expiry_text();
};


class Notes : public Data {
private:
	std::string m_content;

public:
	Notes(std::string title, std::string content);

	std::string content();
};