#include "utils/string.h"
#include "lexer.h"

using namespace std;

// ============================================================

Lexer::Lexer (std::string filename, std::string code)
{
	this->code = code;
	this->pos = -1;
	
	yum();
}

Lexer::~Lexer () {}

// ============================================================

char Lexer::at (int delta)
{
	if (pos < 0 || pos > code.size())
	{
		// Returning a space character, because couldn't return NULL
		return ' ';
	}

	return code[pos + delta];
}

char Lexer::yum (int delta)
{
	if (pos < 0 || pos > code.size())
	{
		pos += delta;
		// Returning a space character, because couldn't return NULL
		return ' ';
	}

	char _char = at();
	pos += delta;
	return _char;
}

bool Lexer::notEOF ()
{
	return pos < code.size();
}

// ============================================================

std::vector<Token> Lexer::lexerize ()
{
	std::vector<Token> tokens;

	while (notEOF())
	{
		// Getting token
		Token token = lexerizeToken();
		
		// Checking
		if (!token.matches(TT_EOF, ""))
		{
			// Pushing
			tokens.push_back( token );
		}

		// std::cout << token.string() << "\n";
		// Advancing
		yum();
	}

	return tokens;
}

Token Lexer::lexerizeToken ()
{
	char _char = at();

	switch (_char)
	{
		// Whitespace
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			// Returning EOF, because I couldn't return NULL
			return Token(TT_EOF, "");
		
		// Operator
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '<':
		case '>':
		case '=':
			if (at(1) == '=')
			{
				yum();
				return Token(TT_OPERATOR, std::string(1, _char) + "=");
			}
			
			return Token(TT_OPERATOR, std::string(1, _char));
		
		// Closure
		case '(':
		case ')':
		case '[':
		case ']':
		case '{':
		case '}':
			return Token(TT_CLOSURE, std::string(1, _char));
		
		// Symbol
		case '.':
		case ',':
		case ':':
		case ';':
		case '!':
		case '?':
		case '&':
		case '|':
			// !=
			if (_char == '!' && at(1) == '=')
			{
				yum();
				return Token(TT_OPERATOR, std::string(1, _char) + "=");
			// &&, ||
			} else if ( _char == at(1) && (_char == '&' || _char == '|') )
			{
				yum();
				return Token(TT_OPERATOR, std::string(1, _char) + std::string(1, _char));
			}
			
			return Token(TT_SYMBOL, std::string(1, _char));
		
		// Number
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			return lexerizeNumber();
		
		// String
		case '"':
		case '\'':
			return lexerizeString();
		
		// Identifier | Keyword
		default:
			return lexerizeIdent();
	}

	// Returning EOF, because I couldn't return NULL
	return Token(TT_EOF, "");
}

// ============================================================

Token Lexer::lexerizeNumber ()
{
	string num_str = "";
	bool dot = false;

	// For some reason, this doesn't work
	// while ( notEOF() && ustr_find("1234567890.", at()) )
	while ( notEOF() &&
	      ( at() == '1' ||
		    at() == '2' ||
			at() == '3' ||
		    at() == '4' ||
			at() == '5' ||
		    at() == '6' ||
			at() == '7' ||
		    at() == '8' ||
			at() == '9' ||
		    at() == '0' ||
			at() == '.' )
	)
	{
		num_str += at();

		if (at() == '.')
		{
			if (dot) break;
			dot = true;
		}

		yum();
	}

	yum(-1);

	return Token(TT_NUMBER, num_str);
}

Token Lexer::lexerizeString ()
{
	string str = "";
	char quote = yum();

	while ( notEOF() && at() != quote )
	{
		str += yum();
	}

	return Token(TT_STRING, str);
}

Token Lexer::lexerizeIdent ()
{
	string ident_str = "";

	while ( notEOF() && !ustr_find(" \t\r\n+-*/%<>=.,:;()[]{}!?&|", at()) )
	{
		ident_str += yum();
	}

	yum(-1);

	if (
		ident_str == "let" ||
		ident_str == "if" ||
		ident_str == "else" ||
		ident_str == "while" ||
		ident_str == "for" ||
		ident_str == "function" ||
		ident_str == "return")
	{
		return Token(TT_KEYWORD, ident_str);
	}

	return Token(TT_IDENT, ident_str);
}