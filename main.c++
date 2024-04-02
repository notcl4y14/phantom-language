#include <iostream>
#include <vector>
#include "src/lexer.h"
#include "src/token.h"

using namespace std;

// ============================================================

void run (std::string filename, std::string code, bool showTokens = false)
{
	std::vector<Token> tokens = Lexer(filename, code).lexerize();

	if (showTokens)
	{
		std::cout << "Tokens ==============================\n";
		for (int i = 0; i < tokens.size(); i++)
		{
			std::cout << tokens.at(i).string() << "\n";
		}
		std::cout << "=====================================\n";
	}
}

// ============================================================

int main (int argc, char const *argv[])
{
	run("<stdin>", "\"Hello World!\"; 10 + 4; let pi = 3; pi += 0.14;", true);
	return 0;
}