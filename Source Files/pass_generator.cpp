#include "../Header Files/pass_generator.h"


Password_Generator::Password_Generator()
	: lowercase_letters("abcdefghijklmnopqrstuvwxyz")
	, uppercase_letters("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
	, digits("0123456789")
	, symbols("!@#$%^") {

}

std::string Password_Generator::generate(int size, bool include_symbols) {
	srand(time(NULL));

	std::string key;

	for (int i = 0; i < size; i++) {
		int choice_category;

		if (include_symbols == true) {
			choice_category = rand() % 4;
		}
		else {
			choice_category = rand() % 3;
		}

		int choice_character;

		switch (choice_category) {
		case 0:
			choice_character = rand() % (lowercase_letters.size());
			key += lowercase_letters[choice_character];
			break;

		case 1:
			choice_character = rand() % (uppercase_letters.size());
			key += uppercase_letters[choice_character];
			break;

		case 2:
			choice_character = rand() % (digits.size());
			key += digits[choice_character];
			break;

		case 3:
			if(include_symbols == true) {
				choice_character = rand() % (symbols.size());
				key += symbols[choice_character];
			}
			break;
		}
		

	}

	return key;
}