#include <vector>
#include <string>
#include "token.h"

enum NodeType
{
	NT_Node,

	// Misc.
	NT_Program,

	// Literals
	NT_NumericLiteral,
	NT_StringLiteral,
	NT_Ident,
	NT_Literal,

	// Statements
	// Expressions
	NT_BinaryExpr,
};

class Node
{
public:
	int type = 0;

	Node ();
	std::string string();
};

// ============================================================
// Misc.
// ============================================================

class Program : public Node
{
public:
	int type = 1;

	std::vector<Node> body;
	Program ();

	void add (Node node);
	std::string string();
};

// ============================================================
// Literals
// ============================================================

class NumericLiteral : public Node
{
public:
	int type = 2;

	double value;
	NumericLiteral (double value);
	std::string string();
};

class StringLiteral : public Node
{
public:
	int type = 3;

	std::string value;
	StringLiteral (std::string value);
	std::string string();
};

class Ident : public Node
{
public:
	int type = 4;

	std::string value;
	Ident (std::string value);
	std::string string();
};

class Literal : public Node
{
public:
	int type = 5;

	std::string value;
	Literal (std::string value);
	std::string string();
};

// ============================================================
// Statements
// ============================================================

// ============================================================
// Expressions
// ============================================================

class BinaryExpr : public Node
{
public:
	int type = 6;

	Node left;
	Token op;
	Node right;

	BinaryExpr (Node left, Token op, Node right);
	std::string string();
};