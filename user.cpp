#include <encryption.h>
#include <user.h>


//--------------------------------------------------------//
// User Class Definitions
//--------------------------------------------------------//


User::User(std::string email, std::string password, Encryption encryption_engine)
	: m_encryptor(encryption_engine)
	, m_email(email)
	, m_password(password) {

}


std::string User::search_item(std::string name) {

}



//--------------------------------------------------------//
// Account Class Definitions
//--------------------------------------------------------//


Account::Account()
	: user(nullptr) {

}


Account::~Account() {

}


bool Account::register_account() {

}


bool Account::sign_in() {

}


void Account::sign_out() {

}



//--------------------------------------------------------//
// IndividualUser Class Definitions
//--------------------------------------------------------//


void add_item() {

}

void edit_item(int index) {

}

void remove_item(int index) {

}

bool change_password(int password, int new_password) {

}

void change_encryption_key() {

}



//--------------------------------------------------------//
// AdministratorUser Class Definitions
//--------------------------------------------------------//


void add_item() {

}


void edit_item(int index) {

}


void remove_item(int index) {

}


bool change_password(int password, int new_password) {

}


void change_encryption_key() {

}


bool delete_user(int index) {

}


bool change_user_password(int password, int email) {

}
