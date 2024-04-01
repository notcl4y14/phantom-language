#include <iostream>
#include "src/token.h"

int main (int argc, char const *argv[])
{
	// std::cout << "Hello World!\n";
	Token token = Token(TT_STRING, "lol");
	std::cout << token.string() << "\n";
	return 0;
}