#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <data.h>
#include <encryption.h>


class User {
private:
	std::string m_email;
	std::string m_password;
	std::string m_encryption_key;
	std::vector<Data> m_item;

public:
	virtual void add_item();

	virtual void edit_item(int index);

	virtual void remove_item(int index);

	virtual void search_item(std::string name);

	virtual bool change_password(int password, int new_password);

	virtual void change_encryption_key();
};


class Account {
public:
	User* user;

	void register_account();

	void sign_in();
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
	bool delete_user(int index);

	bool change_user_password(int index, int password);
};

/*
class Organization : public User {

};


class MemberOrganization : public Organization {

};


class AdminOrgnanization : public Organization {

};
*/