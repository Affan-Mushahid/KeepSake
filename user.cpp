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

User::User(std::string email, std::string password, std::vector<Data*> items) // For existing users
	: m_email(email)
	, m_password(password)
	, m_item(items) {

}


Data* User::search_item(std::string name) {
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

		if (u == normal_user) {
			user = new IndividualUser(email, password);
		}
		else {
			user = new AdministratorUser(email, password);
		}
		return true;
	}

	return false;
}


bool Account::sign_in(user_type u, std::string email, std::string password) {

	// Encrypt since we're gonna check it using txt file which is encrypted
	m_encryptor.encrypt(email);
	m_encryptor.encrypt(password);

	// Depending on user admin or not open different file
	std::string file_open;
	if (u == normal_user) {
		file_open = "normal_user.txt";

	}
	else {
		file_open = "admin_user.txt";
	}

	
	std::ifstream inputf(file_open, std::ios::in); // Opens file for reading
	std::string row;

	std::vector<Data*> items;

	// While there is a user, run instructions
	while (std::getline(inputf, row)) {

		
		std::stringstream s(row); // stringstream so we can use getline on the single user row

		std::string check_email;
		std::string check_password;

		// Taking the email and password from file and comparing
		std::getline(s, check_email, ',');
		std::getline(s, check_password, ',');

		if (email == check_email && password == check_password) {

			std::string element;
			while (std::getline(s, element, ',')) {
				std::stringstream data_stream(element);
				std::string data;

				std::getline(data_stream, data, '~');

				if (data == "Password") {

					std::string title = "";
					std::string website = "";
					std::string pass = "";

					std::getline(data_stream, data, ';');
					std::getline(data_stream, website, ';');
					std::getline(data_stream, pass, ';');

					items.push_back(new Password(title, website, pass));

				}
				else if (data == "CreditCards") {

					std::string title = "";
					std::string card = "";
					std::string SSN = "";
					std::string expiry = "";

					std::getline(data_stream, title, ';');
					std::getline(data_stream, card, ';');
					std::getline(data_stream, SSN, ';');
					std::getline(data_stream, expiry, ';');

					items.push_back(new CreditCards(title, stoi(card), stoi(SSN), stoi(expiry)));

				}
				else if (data == "IdentityCards") {

					std::string title = "";
					std::string full_name = "";
					std::string fathers_name = "";
					Date* date_of_birth;
					Date* date_of_issue;
					Date* date_of_expiry;
					std::string day = "0";
					std::string month = "0";
					std::string year = "0";
					std::string date;
					std::string indv_date = "";

					std::getline(data_stream, title, ';');
					std::getline(data_stream, full_name, ';');
					std::getline(data_stream, fathers_name, ';');
					std::getline(data_stream, date, ';');

					std::stringstream d(date);

					// For birth
					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					date_of_birth = new Date(stoi(day), stoi(month), stoi(year));

					// For issue

					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					date_of_issue = new Date(stoi(day), stoi(month), stoi(year));

					// For expiry
					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					date_of_expiry = new Date(stoi(day), stoi(month), stoi(year));

					items.push_back(new IdentityCards(title, full_name, fathers_name, *date_of_birth, *date_of_issue, *date_of_expiry));

					delete date_of_birth;
					delete date_of_issue;
					delete date_of_expiry;

				}
				else if (data == "Notes") {
					std::string title = "";
					std::string content = "";

					std::getline(data_stream, title, ';');
					std::getline(data_stream, content, ';');

					items.push_back(new Notes(title, content));
				}


			}

			if (u == normal_user) {
				user = new IndividualUser(email, password, items);
			}
			else {
				user = new AdministratorUser(email, password, items);
			}

			return true;

		}

	}

	return false;
}


void Account::sign_out() {

}



//--------------------------------------------------------//
// IndividualUser Class Definitions
//--------------------------------------------------------//

IndividualUser::IndividualUser(std::string email, std::string password)
	: User(email, password) {

}


IndividualUser::IndividualUser(std::string email, std::string password, std::vector<Data*> items)
	: User(email, password, items) {

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


AdministratorUser::AdministratorUser(std::string email, std::string password)
	: User(email, password) {

}

AdministratorUser::AdministratorUser(std::string email, std::string password, std::vector<Data*> items)
	: User(email, password, items) {

}

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
