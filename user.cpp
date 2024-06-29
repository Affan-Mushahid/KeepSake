#include <encryption.h>
#include <user.h>
#include <sstream>

//--------------------------------------------------------//
// User Class Definitions
//--------------------------------------------------------//


User::User(std::string email, std::string password) // For new users
	: m_email(email)
	, m_password(password) {

}

User::User(std::string email, std::string password, std::vector<Data> items) // For existing users
	: m_email(email)
	, m_password(password)
	, m_item(items) {

}


Data User::search_item(std::string name) {
	for (auto item : m_item) {
		// if(item.name() == name) Do Thing

		return item;
	}
}



//--------------------------------------------------------//
// Account Class Definitions
//--------------------------------------------------------//


Account::Account(Encryption encryption_engine)
	: user(nullptr)
	, m_encryptor(encryption_engine) {

}


Account::~Account() {

}


bool Account::register_account(user_type u, std::string email, std::string password) {

	m_encryptor.encrypt(email);
	m_encryptor.encrypt(password);

	std::string file_open;

	if (u == normal_user) {
		file_open = "normal_user.txt";

	}
	else {
		file_open = "admin_user.txt";
	}
	


	std::ofstream outputf(file_open, std::ios::app);

	// If file does not exist
	if (!outputf) {

		std::ofstream outputf(file_open, std::ios::out);
	}
	else { // If file exists

		std::ifstream inputf(file_open, std::ios::in);
		std::string row;

		while (std::getline(inputf, row)) {

			std::stringstream s(row);

			std::string check_email;

			std::getline(s, check_email, ',');

			if (email == check_email) {

				return false;

			}
		}

		outputf << email << "," << password << ",\n";

		m_encryptor.decrypt(email);
		m_encryptor.decrypt(password);

		user = new IndividualUser(email, password);

		return true;
	}

	return false;
}


bool Account::sign_in(user_type u, std::string email, std::string password) {
	/*if (u == normal_user) {
		file_open = "normal_user.txt";

	}
	else {
		file_open = "admin_user.txt";
	}


	std::ifstream inputf(file_open, std::ios::in);
	std::vector<Data*> items;
	std::string element;

	while (std::getline(s, element, ',')) {

		std::stringstream data_stream(element);
		std::string data;

		std::getline(data_stream, data, ' ');

		if (data == "Password") {

			std::string title;
			std::string website;
			std::string pass;

			std::getline(data_stream, data, ';');
			std::getline(data_stream, website, ';');
			std::getline(data_stream, pass, ';');

			items.push_back(new Password(title, website, pass));
		}
		else if (data == "CreditCards") {

			std::string title;
			std::string card;
			std::string SSN;
			std::string expiry;

			std::getline(data_stream, title, ';');
			std::getline(data_stream, card, ';');
			std::getline(data_stream, SSN, ';');
			std::getline(data_stream, expiry, ';');

			items.push_back(new CreditCards(title, stoi(card), stoi(SSN), stoi(expiry)));
		}*/
	return true;
}


void Account::sign_out() {

}



//--------------------------------------------------------//
// IndividualUser Class Definitions
//--------------------------------------------------------//

IndividualUser::IndividualUser(std::string email, std::string password)
	: User(email, password) {

}


void IndividualUser::add_item() {

}


void IndividualUser::edit_item(int index) {

}


void IndividualUser::remove_item(int index) {

}


bool IndividualUser::change_password(int password, int new_password) {
	return true;
}


void IndividualUser::change_encryption_key() {

}



//--------------------------------------------------------//
// AdministratorUser Class Definitions
//--------------------------------------------------------//


void AdministratorUser::add_item() {

}


void AdministratorUser::edit_item(int index) {

}


void AdministratorUser::remove_item(int index) {

}


bool AdministratorUser::change_password(int password, int new_password) {
	return true;
}


void AdministratorUser::change_encryption_key() {

}


bool AdministratorUser::delete_user(int index) {
	return true;
}


bool AdministratorUser::change_user_password(int password, int email) {
	return true;
}
