#include <data.h>



Data::Data(std::string title, std::string data_type)
	: m_title(title)
	, m_data_type(data_type){

}


std::string Data::data_type() {
	return m_data_type;
}

std::string Data::title() {
	return m_title;
}

Password::Password(std::string title, std::string website, std::string pass)
	: Data(title, "Password") {

}

std::string Password::website() {
	return m_website;
}

std::string Password::password() {
	return m_pass;
}

CreditCards::CreditCards(std::string title, int card, int ssn, int expiry)
	: Data(title, "CreditCards") {

}

int CreditCards::card() {
	return 0;
}

int CreditCards::ssn() {
	return 0;
}

int CreditCards::expiry() {
	return 0;
}


Date::Date(int day, int month, int year) {

}


Date::Date(Date& D) {

}

int Date::day() {
	return 0;
}

int Date::month() {
	return 0;
}

int Date::year() {
	return 0;
}


IdentityCards::IdentityCards(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry)
	: Data(title, "IdentityCards")
	, m_date_of_birth(birth)
	, m_date_of_issue(issue)
	, m_date_of_expiry(expiry) {

}

std::string IdentityCards::full_name() {
	return "";
}

std::string IdentityCards::fathers_name() {
	return "";
}

std::string IdentityCards::birth_text() {
	return "";
}

std::string IdentityCards::issue_text() {
	return "";
}

std::string IdentityCards::expiry_text() {
	return "";
}

Notes::Notes(std::string title, std::string content)
	: Data(title, "Notes") {

}

std::string Notes::content() {
	return "";
}