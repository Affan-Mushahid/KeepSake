#include <encryption.h>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>



//--------------------------------------------------------//
// Encryption Class Definitions
//--------------------------------------------------------//


Encryption::Encryption() 
	: lower_case("abcdefghijklmnopqrstuvwxyz")
	, upper_case("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
	setup_crypt();
}


std::string Encryption::encrypt(std::string item) {
	return item;
}


std::string Encryption::decrypt(std::string item) {
	return std::string("");
}


std::string Encryption::setup_crypt() {
	std::string out;
	std::ifstream inputf("encryption.txt", std::ios::in);

	if (!inputf) {

		out = generate_key();

		std::ofstream outputf("encryption.txt", std::ios::out);

		outputf << out;

		outputf.close();

	}
	else {

	}

	return out;
}


std::string Encryption::generate_key() {
	srand(time(NULL));
	std::string key;

	for (int i = 0; i < 4; i++) {
		int choice_category = rand() % 2;
		int choice_character;

		switch (choice_category) {
		case 0:
			choice_character = rand() % (lower_case.size());
			key += lower_case[choice_character];
			break;

		case 1:
			choice_character = rand() % (upper_case.size());
			key += upper_case[choice_character];
			break;
		}

	}

	return key;
}