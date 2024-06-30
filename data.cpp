#include <data.h>



Data::Data(std::string title, std::string data_type)
	: m_title(title)
	, m_data_type(data_type){

}


std::string Data::data_type() {
	return m_data_type;
}


Password::Password(std::string title, std::string website, std::string pass)
	: Data(title, "Password") {

}


CreditCards::CreditCards(std::string title, int card, int ssn, int expiry)
	: Data(title, "CreditCards") {

}


Date::Date(int day, int month, int year) {

}


Date::Date(Date& D) {

}


IdentityCards::IdentityCards(std::string title, std::string full_name, std::string fathers_name, Date birth, Date issue, Date expiry)
	: Data(title, "IdentityCards")
	, m_date_of_birth(birth)
	, m_date_of_issue(issue)
	, m_date_of_expiry(expiry) {

}


Notes::Notes(std::string title, std::string content)
	: Data(title, "Notes") {

}