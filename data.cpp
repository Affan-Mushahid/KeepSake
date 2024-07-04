#include "data.h"


//--------------------------------------------------------//
// Data Class Definitions
//--------------------------------------------------------//


Data::Data(std::string title, std::string data_type)
	: m_title(title)
	, m_data_type(data_type){

}


Data::~Data() {

}


std::string Data::data_type() {
	return m_data_type;
}


std::string Data::title() {
	return m_title;
}


void Data::set_data_type(std::string data) {
	m_data_type = data;
}


void Data::set_title(std::string data) {
	m_title = data;
}



//--------------------------------------------------------//
// Password Class Definitions : Data
//--------------------------------------------------------//


Password::Password(std::string title, std::string website, std::string pass)
	: Data(title, "Password")
	, m_website(website)
	, m_pass(pass) {

}


std::string Password::website() {
	return m_website;
}


std::string Password::password() {
	return m_pass;
}


void Password::edit_item(std::string title, std::string website, std::string password) {
	m_title = title;
	m_website = website;
	m_pass = password;
}



//--------------------------------------------------------//
// Credit Cards Class Definitions : Data
//--------------------------------------------------------//


CreditCards::CreditCards(std::string title, int card, int ssn, std::string expiry)
	: Data(title, "CreditCards")
	, m_card(card)
	, m_SSN(ssn)
	, m_expiry(expiry){

}


int CreditCards::card() {
	return m_card;
}


int CreditCards::ssn() {
	return m_SSN;
}


std::string CreditCards::expiry() {
	return m_expiry;
}


void CreditCards::edit_item(std::string title, int card, int ssn, std::string expiry) {
	m_title = title;
	m_card = card;
	m_SSN = ssn;
	m_expiry = expiry;
}



//--------------------------------------------------------//
// Date Class Definitions
//--------------------------------------------------------//


Date::Date(int day, int month, int year)
	: m_day(day)
	, m_month(month)
	, m_year(year) {
	
}


Date::Date(Date& D) {
	m_day = D.day();
	m_month = D.month();
	m_year = D.year();
}


int Date::day() {
	return m_day;
}


int Date::month() {
	return m_month;
}


int Date::year() {
	return m_year;
}


std::string Date::get_date() {
	std::string output;

	output = std::to_string(m_day) + "-" + std::to_string(m_month) + "-" + std::to_string(m_year) + "-";

	return output;
}


//--------------------------------------------------------//
// Identity Class Definitions : Data
//--------------------------------------------------------//


IdentityCards::IdentityCards(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry)
	: Data(title, "IdentityCards")
	, m_date_of_birth(birth)
	, m_date_of_issue(issue)
	, m_date_of_expiry(expiry) {

}


std::string IdentityCards::full_name() {
	return m_full_name;
}


std::string IdentityCards::fathers_name() {
	return m_fathers_name;
}


std::string IdentityCards::birth() {
	return m_date_of_birth.get_date();
}


std::string IdentityCards::issue() {
	return m_date_of_issue.get_date();
}


std::string IdentityCards::expiry() {
	return m_date_of_issue.get_date();
}


void IdentityCards::edit_item(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry) {
	m_title = title;
	m_full_name = full_name;
	m_fathers_name = fathers_name;
	m_date_of_birth = birth;
	m_date_of_issue = issue;
	m_date_of_expiry = expiry;
}



//--------------------------------------------------------//
// Notes Class Definitions : Data
//--------------------------------------------------------//


Notes::Notes(std::string title, std::string content)
	: Data(title, "Notes")
	, m_content(content) {

}


std::string Notes::content() { 
	return m_content;
}


void Notes::edit_item(std::string title, std::string content) {
	m_title = title;
	m_content = content;
}