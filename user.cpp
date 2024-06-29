#include <encryption.h>
#include <user.h>


//--------------------------------------------------------//
// User Class Definitions
//--------------------------------------------------------//


User::User(std::string email, std::string password)
	: m_email(email)
	, m_password(password) {

}


Data User::search_item(std::string name) {
	for (auto item : m_item) {
		// if(item.name() == name) Do Thing
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

	if (u == normal_user) {


		std::ofstream outputf("normal_user.txt", std::ios::app);

		if (!outputf) {
			std::ofstream outputf("normal_user.txt", std::ios::out);
			

			outputf << email << "," << password;
		}
		


	}
	else {
		std::ofstream outputf("admin_user.txt", std::ios::app);

		if (!outputf) {
			std::ofstream outputf("admin_user.txt", std::ios::out);


		}
	}
}


bool Account::sign_in() {

}


void Account::sign_out() {

}



//--------------------------------------------------------//
// IndividualUser Class Definitions
//--------------------------------------------------------//


void IndividualUser::add_item() {

}

void IndividualUser::edit_item(int index) {

}

void IndividualUser::remove_item(int index) {

}

bool IndividualUser::change_password(int password, int new_password) {

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

}


void AdministratorUser::change_encryption_key() {

}


bool AdministratorUser::delete_user(int index) {

}


bool AdministratorUser::change_user_password(int password, int email) {

}
