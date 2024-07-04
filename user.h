#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <data.h>
#include <encryption.h>
#include <pass_generator.h>

enum user_type{normal_user = 0, admin_user = 1};


class User {
private:
	std::string m_email;
	std::string m_password;
	std::vector<Data *> m_item;
	user_type m_user;
	Password_Generator& m_password_generator;


public:
	User(user_type user, std::string email, std::string password, Password_Generator& password_engine);
	User(user_type user, std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine);

	void add_item(Data* item_to_add);

	void remove_item(Data* item_to_remove);

	Data* search_item(std::string name);

	bool change_email(std::string email);

	bool change_password(std::string password);

	std::string email();
	
	std::string password();

	std::vector<Data*>& items();
};


class Account {
public:
	User* user;
	Encryption& m_encryptor;

	Account(Encryption& encryption_engine);

	~Account();

	bool register_account(user_type u, std::string email, std::string password, Password_Generator& password_engine);

	bool sign_in(user_type u, std::string email, std::string password, Password_Generator& password_engine);

	void sign_out(user_type u);
};


class IndividualUser : public User {

public:
	IndividualUser(std::string email, std::string password, Password_Generator& password_engine);

	IndividualUser(std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine);
};


class AdministratorUser : public User {
public:
	AdministratorUser(std::string email, std::string password, Password_Generator& password_engine);

	AdministratorUser(std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine);

	void add_item();

	void remove_item(int index);

	bool change_password(std::string new_password);

	bool change_user_password(std::string password, std::string email);
};