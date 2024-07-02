#include <encryption.h>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

//--------------------------------------------------------//
// Encryption Class Definitions
//--------------------------------------------------------//

std::string Encryption::encrypt(std::string item) {
	return item;
}


std::string Encryption::decrypt(std::string item) {
	return std::string("");
}


std::string Encryption::create_crypt() {
	std::string out = generate_key();
	std::ifstream inputf("encryption.txt", std::ios::in);

	if (!inputf) {
		std::ofstream outputf("encryption.txt", std::ios::out);

	}
	else {

	}

	return out;
}


std::string Encryption::generate_key() {
	srand(time(NULL));
	std::string key;
	std::string low = "abcdefghijklmnopqrstuvwxyz";
	std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string special = "!@#$%";

	for (int i = 0; i < 4; i++) {
		int choice_category = rand() % 2;
		int choice_character;

		switch (choice_category) {
		case 0:
			choice_character = rand() % (low.size() - 1);
			key += low[choice_character];
			break;

		case 1:
			choice_character = rand() % (upper.size() - 1);
			key += upper[choice_character];
			break;

		case 2:
			choice_character = rand() % (special.size() - 1);
			key += special[choice_character];
			break;
		}

	}

	return key;
}