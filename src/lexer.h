#include <vector>
#include <string>
#include "token.h"

class Lexer
{
public:
	std::string code;
	int pos;

	Lexer (std::string filename, std::string code);
	~Lexer ();

	char at (int delta = 0);
	char yum (int delta = 1);
	bool notEOF ();

	std::vector<Token> lexerize ();
	Token lexerizeToken ();

	Token lexerizeNumber ();
	Token lexerizeString ();
	Token lexerizeIdent ();
};