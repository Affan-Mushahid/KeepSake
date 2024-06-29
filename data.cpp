#include <data.h>


Password::Password(std::string title, std::string website, std::string pass)
	: Data() {

}


CreditCards::CreditCards(std::string title, int card, int ssn, int expiry)
	: Data() {

}


Date::Date(int day, int month, int year) {

}


Date::Date(Date& D) {

}


IdentityCards::IdentityCards(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry)
	: Data()
	, m_date_of_birth(birth)
	, m_date_of_issue(issue)
	, m_date_of_expiry(expiry) {

}


Notes::Notes(std::string title, std::string content)
	: Data() {

}