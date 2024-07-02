#include <encryption.h>
#include <fstream>
#include <string>


//--------------------------------------------------------//
// Encryption Class Definitions
//--------------------------------------------------------//

std::string Encryption::encrypt(std::string item) {
	return std::string("");
}


std::string Encryption::decrypt(std::string item) {
	return std::string("");
}


std::string Encryption::create_crypt() {

	std::ifstream inputf("encryption.txt", std::ios::in);

	if(inputf)
}