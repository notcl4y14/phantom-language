#include <vector>
#include <string>
#include "nodes.h"
#include "token.h"

class Parser
{
public:
	std::vector<Token> tokens;
	int pos;

	Parser (std::vector<Token> tokens);
	
	Token at (int delta = 0);
	Token yum ();
	Token yumCheck (int type, std::string value = NULL);
	bool notEOF ();

	Program parse ();

	Node parse_Stmt ();
	Node parse_Expr ();

	// Node parse_BinaryExpr (std::vector<std::string> ops, Node (*func)());

	Node parse_AdditiveExpr ();
	Node parse_MultExpr ();

	Node parse_PrimaryExpr ();
};