#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <data.h>
//#include <encryption.h>

class Encryption; //forward declaring due to circular dependancies of classes


class User {
private:
	std::string m_email;
	std::string m_password;
	std::string m_encryption_key;
	std::vector<Data> m_item;
	Encryption& m_encryptor;

public:
	User(std::string email, std::string password, Encryption encryption_engine);

	virtual void add_item() = 0;

	virtual void edit_item(int index) = 0;

	virtual void remove_item(int index) = 0;

	std::string search_item(std::string name);

	virtual bool change_password(int password, int new_password) = 0;

	virtual void change_encryption_key() = 0;
};


class Account {
public:
	User* user;

	Account();

	~Account();

	bool register_account();

	bool sign_in();

	void sign_out();
};


class IndividualUser : public User {
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

	bool change_user_password(int index, int password, int email);
};

/*
class Organization : public User {

};


class MemberOrganization : public Organization {

};


class AdminOrgnanization : public Organization {

};
*/