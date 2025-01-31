#include "../Header Files/user.h"



//--------------------------------------------------------//
// User Class Definitions
//--------------------------------------------------------//


User::User(user_type user, std::string email, std::string password, Password_Generator& password_engine, Encryption& encryptor) // For new users
	: m_user(user)
	, m_email(email)
	, m_password(password)
	, m_password_generator(password_engine)
	, m_encryptor(encryptor){

}

User::User(user_type user, std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine, Encryption& encryptor) // For existing users
	: m_user(user)
	, m_email(email)
	, m_password(password)
	, m_item(items) 
	, m_password_generator(password_engine)
	, m_encryptor(encryptor) {

}

User::~User() {

}

void User::add_item(Data* item_to_add){
	for (int i = 0; i < m_item.size(); i++) {
		if (m_item[i]->title() == item_to_add->title()) {
			return;
		}
	}

	m_item.push_back(item_to_add);
	return;
}


void User::remove_item(Data* item_to_remove) {
	for (int i = 0; i < m_item.size(); i++) {
		if (item_to_remove->title() == m_item[i]->title()) {
			delete m_item[i];
			m_item.erase(m_item.begin() + i);
			break;
		}
	}

	return;
}


bool User::change_email(std::string new_email) {
	m_email;
	m_password;
	std::string old_email = m_encryptor.encrypt(m_email);
	std::string password = m_encryptor.encrypt(m_password);
	
	m_email = new_email;

	std::string file_open;

	if (m_user == normal_user) {
		file_open = "normal_user.txt";
	}
	else {
		file_open = "admin_user.txt";
	}

	std::ifstream inputf(file_open, std::ios::in);
	std::ofstream outputf("temp_" + file_open, std::ios::out | std::ios::trunc);

	std::string row;

	while (std::getline(inputf, row)) {
		std::stringstream s(row); // stringstream so we can use getline on the single user row

		std::string check_email;
		std::string check_password;

		// Taking the email and password from file and comparing
		std::getline(s, check_email, ',');
		std::getline(s, check_password, ',');

		if (check_email == old_email) {
			outputf << m_encryptor.encrypt(new_email) << "," << password << ",";

			std::string element;

			std::getline(s, element);

			outputf << element << "\n";

		}
		else {
			outputf << row << "\n";

		}
	}

	outputf.close();
	inputf.close();

	std::ifstream inputf_write_back("temp_" + file_open, std::ios::in); // Opens temp file for reading 
	std::ofstream outputf_write_back(file_open, std::ios::out | std::ios::trunc); // Writes the changes we have made back to file

	while (std::getline(inputf_write_back, row)) {
		outputf_write_back << row << "\n";
	}

	inputf_write_back.close();
	outputf_write_back.close();

	return true;
}


bool User::change_password(std::string password) {
	m_password = password;
	return true;
}


Data* User::search_item(std::string name) {
	for (auto item : m_item) {
		// if(item.name() == name) Do Thing

		return item;
	}
}


std::vector<Data*>& User::items() {
	return m_item;
}

std::string User::email() {
	return m_email;
}

std::string User::password() {
	return m_password;
}

//--------------------------------------------------------//
// Account Class Definitions
//--------------------------------------------------------//


Account::Account(Encryption& encryption_engine)
	: user(nullptr)
	, m_encryptor(encryption_engine) {

}


Account::~Account() {
	delete user;
}


bool Account::register_account(user_type u, std::string email, std::string password, Password_Generator& password_engine) {

	email = m_encryptor.encrypt(email);
	password = m_encryptor.encrypt(password);

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

		std::ofstream outputf(file_open, std::ios::out); // Useless line of code, delete
	}
	else { // If file exists

		std::ifstream inputf(file_open, std::ios::in);
		std::string row;

		while (std::getline(inputf, row)) {

			std::stringstream s(row);

			std::string check_email;

			std::getline(s, check_email, ',');

			if (email == check_email) {
				inputf.close();
				outputf.close();
				return false;

			}
		}

		outputf << email << "," << password << ",\n";

		email = m_encryptor.decrypt(email);
		password = m_encryptor.decrypt(password);

		if (u == normal_user) {
			user = new IndividualUser(email, password, password_engine, m_encryptor); 
		}
		else {
			user = new AdministratorUser(email, password, password_engine, m_encryptor); 
		}
		inputf.close();
		outputf.close();
		return true;
	}

	return false;
}


bool Account::sign_in(user_type u, std::string email, std::string password, Password_Generator& password_engine) {

	// Encrypt since we're gonna check it using txt file which is encrypted
	email = m_encryptor.encrypt(email);
	password = m_encryptor.encrypt(password);

	// Depending on user admin or not open different file
	std::string file_open;
	if (u == normal_user) {
		file_open = "normal_user.txt";

	}
	else {
		file_open = "admin_user.txt";
	}

	
	std::ifstream inputf(file_open, std::ios::in); // Opens file for reading

	if (!inputf) {
		return false;
	}

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

			
			std::string element; // This will store a single Data element

			// For every element in a user, do this
			while (std::getline(s, element, ',')) {

				std::stringstream data_stream(element); // converted so we can use getline

				std::string data; // Type of Data

				std::getline(data_stream, data, '~');

				if (m_encryptor.decrypt(data) == "Password") {

					std::string title = "";
					std::string website = "";
					std::string pass = "";

					std::getline(data_stream, title, ';');
					std::getline(data_stream, website, ';');
					std::getline(data_stream, pass, ';');

					items.push_back(new Password(m_encryptor.decrypt(title), m_encryptor.decrypt(website), m_encryptor.decrypt(pass)));

				}
				else if (m_encryptor.decrypt(data) == "CreditCards") {

					std::string title = "";
					std::string card = "";
					std::string SSN = "";
					std::string expiry = "";
					std::string date = "";
					std::string day = ""; 
					std::string month = ""; 
					std::string year = ""; 
					Date* date_of_expiry; 

					std::getline(data_stream, title, ';');
					std::getline(data_stream, card, ';');
					std::getline(data_stream, SSN, ';');
					std::getline(data_stream, date, ';'); 

					std::stringstream d(date);

					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					date_of_expiry = new Date(stoll(m_encryptor.decrypt(day)),
						stoll(m_encryptor.decrypt(month)),
						stoll(m_encryptor.decrypt(year))
					);

					items.push_back(new CreditCards(m_encryptor.decrypt(title),
										stoll(m_encryptor.decrypt(card)), 
										stoll(m_encryptor.decrypt(SSN)), 
										*date_of_expiry)
					);

				}
				else if (m_encryptor.decrypt(data) == "IdentityCards") {

					std::string title = "";
					std::string full_name = "";
					std::string fathers_name = "";
					Date* date_of_birth;
					Date* date_of_issue;
					Date* date_of_expiry;
					std::string day = "";
					std::string month = "";
					std::string year = "";
					std::string date;

					std::getline(data_stream, title, ';');
					std::getline(data_stream, full_name, ';');
					std::getline(data_stream, fathers_name, ';');
					std::getline(data_stream, date, ';');

					std::stringstream d(date);

					// For birth
					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					std::string test = m_encryptor.decrypt(day);
					date_of_birth = new Date(stoll(m_encryptor.decrypt(day)),
										stoll(m_encryptor.decrypt(month)), 
										stoll(m_encryptor.decrypt(year))
					);

					// For issue

					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					//std::string test = m_encryptor.decrypt(day);
					date_of_issue = new Date(stoll(m_encryptor.decrypt(day)),
						stoll(m_encryptor.decrypt(month)),
						stoll(m_encryptor.decrypt(year))
					);

					// For expiry
					std::getline(d, day, '-');
					std::getline(d, month, '-');
					std::getline(d, year, '-');

					date_of_expiry = new Date(stoll(m_encryptor.decrypt(day)),
						stoll(m_encryptor.decrypt(month)),
						stoll(m_encryptor.decrypt(year))
					);


					items.push_back(new IdentityCards(m_encryptor.decrypt(title),
										m_encryptor.decrypt(full_name), 
										m_encryptor.decrypt(fathers_name), 
										*date_of_birth, 
										*date_of_issue, 
										*date_of_expiry)
					);

					delete date_of_birth;
					delete date_of_issue;
					delete date_of_expiry;

				}
				else if (m_encryptor.decrypt(data) == "Notes") {
					std::string title = "";
					std::string content = "";

					std::getline(data_stream, title, ';');
					std::getline(data_stream, content, ';');

					items.push_back(new Notes(m_encryptor.decrypt(title), 
										m_encryptor.decrypt(content))
					);

				}


			}

			email = m_encryptor.decrypt(email);
			password = m_encryptor.decrypt(password);

			if (u == normal_user) {
				user = new IndividualUser(email, password, items, password_engine, m_encryptor);
			}
			else {
				user = new AdministratorUser(email, password, items, password_engine, m_encryptor);
			}
			inputf.close();
			return true;

		}

	}
	inputf.close();
	return false;
}


void Account::sign_out(user_type u) {
	// Encrypt since we're gonna check it using txt file which is encrypted
	//user->change_email(m_encryptor.encrypt(user->email()));
	//user->change_password(m_encryptor.encrypt(user->password()));

	std::string email = m_encryptor.encrypt(user->email());
	std::string password = m_encryptor.encrypt(user->password()); 

	// Depending on user admin or not open different file
	std::string file_open;
	if (u == normal_user) {
		file_open = "normal_user.txt";

	}
	else {
		file_open = "admin_user.txt";
	}

	std::ifstream inputf(file_open, std::ios::in); // Opens file for reading
	std::ofstream outputf("temp_" + file_open, std::ios::out | std::ios::trunc); // Opens file for writing

	std::string row;

	while (std::getline(inputf, row)) {
		std::stringstream s(row); // stringstream so we can use getline on the single user row

		std::string check_email;

		// Taking the email and password from file and comparing
		std::getline(s, check_email, ',');

		if (email == check_email) {

			std::string element; // This will store a single Data element

			outputf << email << "," << password << ",";

			// Go through every element, write it in file
			for (int i = 0; i < user->items().size(); i++) {

				// For Password
				if (((user->items())[i])->data_type() == "Password") {

					Password* item = dynamic_cast<Password*>(user->items()[i]);

					outputf << m_encryptor.encrypt("Password") << "~" << m_encryptor.encrypt(item->title()) + ";"
						<< m_encryptor.encrypt(item->website()) + ";"
						<< m_encryptor.encrypt(item->password()) + ";" << ",";

				}

				// For Credit Cards
				else if (((user->items())[i])->data_type() == "CreditCards") {

					CreditCards* item = dynamic_cast<CreditCards*>(user->items()[i]);

					outputf << m_encryptor.encrypt("CreditCards") << "~" << m_encryptor.encrypt(item->title()) + ";"
						<< m_encryptor.encrypt(std::to_string(item->card())) + ";"
						<< m_encryptor.encrypt(std::to_string(item->ssn())) + ";"
						<< m_encryptor.encrypt(std::to_string(item->expiry().day())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->expiry().month())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->expiry().year())) + "-" + ";" << ",";

				}

				// For Identity Cards
				else if (((user->items())[i])->data_type() == "IdentityCards") {

					IdentityCards* item = dynamic_cast<IdentityCards*>(user->items()[i]);

					outputf << m_encryptor.encrypt("IdentityCards") << "~" << m_encryptor.encrypt(item->title()) + ";"
						<< m_encryptor.encrypt(item->full_name()) + ";"
						<< m_encryptor.encrypt(item->fathers_name()) + ";"
						<< m_encryptor.encrypt(std::to_string(item->birth().day())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->birth().month())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->birth().year())) + "-"

						<< m_encryptor.encrypt(std::to_string(item->issue().day())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->issue().month())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->issue().year())) + "-"

						<< m_encryptor.encrypt(std::to_string(item->expiry().day())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->expiry().month())) + "-"
						<< m_encryptor.encrypt(std::to_string(item->expiry().year())) + "-" + ";" << ",";

				}

				// For Notes
				else if (((user->items())[i])->data_type() == "Notes") {

					Notes* item = dynamic_cast<Notes*>(user->items()[i]);

					outputf << m_encryptor.encrypt("Notes") << "~" << m_encryptor.encrypt(item->title()) + ";"
						<< m_encryptor.encrypt(item->content()) + ";" << ",";

				}

			}

			outputf << "\n";

		}
		else {

			outputf << row << "\n";

		}

	}

	outputf.close();

	inputf.close();

	std::string row_write_back;

	std::ifstream inputf_write_back("temp_" + file_open, std::ios::in); // Opens temp file for reading 
	std::ofstream outputf_write_back(file_open, std::ios::out); // Writes the changes we have made back to file

	while (std::getline(inputf_write_back, row_write_back)) {
		outputf_write_back << row_write_back << "\n";
	}

	delete user;

	outputf_write_back.close();
	inputf_write_back.close(); 
	return;
}



//--------------------------------------------------------//
// IndividualUser Class Definitions
//--------------------------------------------------------//

IndividualUser::IndividualUser(std::string email, std::string password, Password_Generator& password_engine, Encryption& encryptor)
	: User(user_type(normal_user), email, password, password_engine, encryptor) {

}


IndividualUser::IndividualUser(std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine, Encryption& encryptor)
	: User(user_type(normal_user), email, password, items, password_engine, encryptor) {

}



//--------------------------------------------------------//
// AdministratorUser Class Definitions
//--------------------------------------------------------//


AdministratorUser::AdministratorUser(std::string email, std::string password, Password_Generator& password_engine, Encryption& encryptor)
	: User(user_type(admin_user), email, password, password_engine, encryptor) {

}


AdministratorUser::AdministratorUser(std::string email, std::string password, std::vector<Data*> items, Password_Generator& password_engine, Encryption& encryptor)
	: User(user_type(admin_user), email, password, items, password_engine, encryptor) {

}


bool AdministratorUser::change_user_password(std::string password, std::string email) {

	email = m_encryptor.encrypt(email);
	password = m_encryptor.encrypt(password);

	std::ifstream inputf("normal_user.txt", std::ios::in);
	std::ofstream outputf("temp_normal_user.txt", std::ios::out | std::ios::trunc);

	std::string row;

	while (std::getline(inputf, row)) {
		std::stringstream s(row); // stringstream so we can use getline on the single user row

		std::string check_email;
		std::string check_password;

		// Taking the email and password from file and comparing
		std::getline(s, check_email, ',');
		std::getline(s, check_password, ',');

		if (check_email == email) {
			outputf << email << "," << password << ",";

			std::string element;

			std::getline(s, element);

			outputf << element << "\n";

		}
		else {
			outputf << row << "\n";

		}
	}

	outputf.close();

	inputf.close();

	std::ifstream inputf_write_back("temp_normal_user.txt", std::ios::in); // Opens temp file for reading 
	std::ofstream outputf_write_back("normal_user.txt", std::ios::out | std::ios::trunc); // Writes the changes we have made back to file

	while (std::getline(inputf_write_back, row)) {
		outputf_write_back << row << "\n";
	}

	inputf_write_back.close();
	outputf_write_back.close();

	return true;
}
