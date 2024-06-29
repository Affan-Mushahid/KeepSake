#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <data.h>
//#include <encryption.h>

enum user_type{normal_user = 0, admin_user = 1};

class Encryption; //forward declaring due to circular dependancies of classes


class User {
private:
	std::string m_email;
	std::string m_password;
	std::vector<Data> m_item;

public:
	User(std::string email, std::string password);
	User(std::string email, std::string password, std::vector<Data> items);

	virtual void add_item() = 0;

	virtual void edit_item(int index) = 0;

	virtual void remove_item(int index) = 0;

	Data search_item(std::string name);

	virtual bool change_password(int password, int new_password) = 0;

	virtual void change_encryption_key() = 0;
};


class Account {
public:
	User* user;
	Encryption& m_encryptor;

	Account(Encryption encryption_engine);

	~Account();

	bool register_account(user_type u, std::string email, std::string password);

	bool sign_in(user_type u, std::string email, std::string password);

	void sign_out();
};


class IndividualUser : public User {

public:
	IndividualUser(std::string email, std::string password);

	void add_item();

	void edit_item(int index);

	void remove_item(int index);

	bool change_password(int password, int new_password);

	void change_encryption_key();
};


class AdministratorUser : public User {
public:
	void add_item();

	void edit_item(int index);

	void remove_item(int index);

	bool change_password(int password, int new_password);

	void change_encryption_key();

	bool delete_user(int index);

	bool change_user_password(int password, int email);
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