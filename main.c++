#include <iostream>
#include <algorithm>
#include <vector>
#include "src/utils/arr.h"
#include "src/utils/file.h"
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

std::vector<std::string> parse_args (int argc, char const *argv[])
{
	std::string valid_args[] = { "--show-tokens" };
	std::vector<std::string> args;

	for (int i = 0; i < argc; i++)
	{
		std::string str = argv[i];
		bool isParam = str[0] == '-';

		if (isParam && !uarr_find(valid_args, str))
		{
			std::cout << "Undefined argument \"" << str << "\"!";
			std::exit(1);
		}

		args.push_back(str);
	}

	return args;
}
std::string get_filename (std::vector<std::string> args)
{
	args.erase(args.begin());
	
	for (int i = 0; i < args.size(); i++)
	{
		if (args.at(i)[0] != '-')
		{
			return args.at(i);
		}
	}

	return "";
}

// ============================================================

int main (int argc, char const *argv[])
{
	std::vector<std::string> args = parse_args(argc, argv);
	std::string filename = get_filename(args);
	std::string code = ufile_read(filename);

	if (filename == "")
	{
		std::cout << "Please specify a filename!";
		return 1;
	}

	if (code == "")
	{
		std::cout << "File \"" << filename << "\" not found!";
		return 1;
	}

	bool showTokens = uarr_find(args, "--show-tokens");

	run(filename, code, showTokens);
	return 0;
}