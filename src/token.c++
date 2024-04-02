#include "token.h"

using namespace std;

Token::Token (TokenType type, std::string value)
{
	this->type = type;
	this->value = value;
}

Token::~Token () {}

bool Token::matches (TokenType type, std::string value)
{
	return this->type == type && this->value == value;
}

std::string Token::string ()
{
	std::string type = to_string(this->type);

	// "Type:	Value"
	return type + ":\t\"" + value + "\"";
}