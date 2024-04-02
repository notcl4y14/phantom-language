#pragma once

#include <string>
#include <map>

enum TokenType
{
	TT_NUMBER,
	TT_STRING,
	TT_IDENT,
	TT_KEYWORD,
	TT_OPERATOR,
	TT_CLOSURE,
	TT_SYMBOL,
	TT_COMMENT,
	TT_EOF
};

class Token
{
public:
	TokenType type;
	std::string value;

	Token (TokenType type, std::string value);
	~Token ();

	bool matches (TokenType type, std::string value);
	std::string string ();
};