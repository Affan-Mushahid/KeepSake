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
	int current_letter = 0;
	std::string encrypted_text = "";

	for (int i = 0; i < item.size(); i++) {
		if (current_letter > 3) {
			current_letter = 0;
		}

		encrypted_text += std::to_string(int(item[i] ^ m_encryption_key[current_letter])) + ' ';

		current_letter++;
	}


	return encrypted_text;
}

std::string Encryption::decrypt(std::string encrypted_text) {
	int current_letter = 0;
	std::string decrypted_text = "";

	std::string word = "";
	std::string text = "";
	//std::to_string(int(encrypted_text));

	for (int i = 0; i < encrypted_text.size(); i++) {
		if (encrypted_text[i] == ' ') {
			text += char(stoi(word));
			word = "";
			continue;
		}

		word += encrypted_text[i];
	}

	for (int i = 0; i < text.size(); i++) {
		if (current_letter > 3) {
			current_letter = 0;
		}

		decrypted_text += text[i] ^ m_encryption_key[current_letter];

		current_letter++;
	}


	return decrypted_text;
}


void Encryption::setup_crypt() {
	std::string out;
	std::ifstream inputf("encryption.txt", std::ios::in);

	if (!inputf) {

		out = generate_key();

		std::ofstream outputf("encryption.txt", std::ios::out);

		outputf << out;

		m_encryption_key = out;

		outputf.close();

	}
	else {
		std::getline(inputf, out);
		m_encryption_key = out;
		inputf.close();
	}

	return;
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