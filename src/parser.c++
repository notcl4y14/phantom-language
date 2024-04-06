#include "parser.h"
#include "utils/arr.h"

// ============================================================

Parser::Parser (std::vector<Token> tokens)
{
	this->tokens = tokens;
	this->pos = -1;

	yum();
}

// ============================================================

Token Parser::at (int delta = 0) {
	if (pos < 0 || pos > tokens.size())
	{
		return tokens[tokens.size() - 1];
	}
	
	return tokens[pos + delta];
}

Token Parser::yum ()
{
	Token prev = at();
	pos++;
	return prev;
}

Token Parser::yumCheck (int type, std::string value = "")
{
	Token prev = at();
	pos++;

	if (prev.type != type) {
		throw "Expected \"" + value + "\"";
	}

	if (value != "" && prev.value != value)
	{
		throw "Expected \"" + value + "\"";
	}

	return prev;
}

bool Parser::notEOF ()
{
	return pos < tokens.size();
}

// ============================================================

Program Parser::parse ()
{
	Program program = Program();

	while (notEOF())
	{
		Node expr = parse_Stmt();

		if (expr.type != 0)
		{
			program.add(expr);
		}
	}
}

// ============================================================

Node Parser::parse_Stmt ()
{
	return parse_Expr();
}

Node Parser::parse_Expr ()
{
	return parse_AdditiveExpr();
}

// ============================================================

// Node Parser::parse_BinaryExpr (std::vector<std::string> ops, Node (*func)())
// {
// 	Node left = func();

// 	while ( notEOF() && at().type == TT_OPERATOR && uarr_find(ops, at().value) )
// 	{
// 		Token op = yum();
// 		Node right = func();

// 		left = BinaryExpr(left, op, right);
// 	}

// 	return left;
// }

Node Parser::parse_AdditiveExpr ()
{
	// return parse_BinaryExpr (std::vector<std::string> { "+", "-" }, parse_MultExpr );
	
	Node left = parse_MultExpr();

	while ( notEOF() && at().type == TT_OPERATOR && ( at().value == "+" || at().value == "-" ) )
	{
		Token op = yum();
		Node right = parse_MultExpr();

		left = BinaryExpr(left, op, right);
	}

	return left;
}

Node Parser::parse_MultExpr ()
{
	// return parse_BinaryExpr (std::vector<std::string> { "+", "-" }, parse_MultExpr );
	
	Node left = parse_PrimaryExpr();

	while ( notEOF() && at().type == TT_OPERATOR && ( at().value == "*" || at().value == "/" || at().value == "%" ) )
	{
		Token op = yum();
		Node right = parse_PrimaryExpr();

		left = BinaryExpr(left, op, right);
	}

	return left;
}

// ============================================================

Node Parser::parse_PrimaryExpr ()
{
	Token token = yum();

	if (token.type == TT_NUMBER)
	{
		return NumericLiteral (stod(token.value));
	} else if (token.type == TT_STRING)
	{
		return StringLiteral (token.value);
	} else if (token.type == TT_IDENT)
	{
		if (token.value == "null" || token.value == "true" || token.value == "false")
		{
			return Literal (token.value);
		}

		return Ident (token.value);
	}

	throw "Unexpected token \"" + token.value + "\"";
}