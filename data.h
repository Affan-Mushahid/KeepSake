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
	virtual ~Data() = 0;

	std::string data_type();
	std::string title();
	void set_data_type(std::string data);
	void set_title(std::string data);

};


class Password : public Data {
private:
	std::string m_website;
	std::string m_pass;

public:
	Password(std::string title, std::string website, std::string pass);
	std::string website();
	std::string password();
	void edit_item(std::string title, std::string website, std::string password);
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

	std::string get_date();
};


class CreditCards : public Data {
private:
	long long int m_card;
	long long int m_SSN;
	Date m_expiry;

public:
	CreditCards(std::string title, long long int card, long long int ssn, Date expiry);

	long long int card();

	long long int ssn();

	Date expiry();

	void edit_item(std::string title, long long int card, long long int ssn, Date expiry);
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

	Date birth();

	Date issue();

	Date expiry();

	void edit_item(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry);
};


class Notes : public Data {
private:
	std::string m_content;

public:
	Notes(std::string title, std::string content);

	std::string content();

	void edit_item(std::string title, std::string content);
};