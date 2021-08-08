#include <iostream>

#include "recognizer.h"

int main() {
	std::string input;
	std::cout << "> ";
	std::getline(std::cin, input);
	while (input != "quit") {
		std::vector<std::string> intents = recognizeIntents(input);
		std::cout << "Intent:";
		for (const std::string& intent : intents) {
			std::cout << " " << intent;
		}
		std::cout << std::endl << "> ";
		std::getline(std::cin, input);
	} 
	return 0;
}