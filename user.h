#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <data.h>
//#include <encryption.h>

enum user_type{normal_user = 0, admin_user = 1};

class Encryption; //forward declaring due to circular dependancies of classes


class User {
private:
	std::string m_email;
	std::string m_password;
	std::vector<Data *> m_item;
	user_type m_user;

public:
	User(user_type user, std::string email, std::string password);
	User(user_type user, std::string email, std::string password, std::vector<Data*> items);

	virtual void add_item() = 0;

	virtual void edit_item(int index) = 0;

	virtual void remove_item(int index) = 0;

	Data* search_item(std::string name);

	virtual bool change_password(std::string password, std::string new_password) = 0;

	//virtual void change_encryption_key() = 0;

	std::string email();
	
	std::string password();

	std::vector<Data*>& items();
};


class Account {
public:
	User* user;
	Encryption& m_encryptor;

	Account(Encryption encryption_engine);

	~Account();

	bool register_account(user_type u, std::string email, std::string password);

	bool sign_in(user_type u, std::string email, std::string password);

	void sign_out(user_type u);
};


class IndividualUser : public User {

public:
	IndividualUser(std::string email, std::string password);

	IndividualUser(std::string email, std::string password, std::vector<Data*> items);

	void add_item();

	void edit_item(int index);

	void remove_item(int index);

	bool change_password(std::string password, std::string new_password);

	//void change_encryption_key();
};


class AdministratorUser : public User {
public:
	AdministratorUser(std::string email, std::string password);

	AdministratorUser(std::string email, std::string password, std::vector<Data*> items);

	void add_item();

	void edit_item(int index);

	void remove_item(int index);

	bool change_password(std::string password, std::string new_password);

	void change_encryption_key();

	bool delete_user(std::string email);

	bool change_user_password(std::string password, std::string email);
};


// Remove At The End

/*
class Organization : public User {

};


class MemberOrganization : public Organization {

};


class AdminOrgnanization : public Organization {

};
*/