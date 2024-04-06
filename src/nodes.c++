#include "nodes.h"

using namespace std;

// Node

Node::Node () {}

std::string Node::string ()
{
	return "Node (" + to_string(type) + ")";
}

// ============================================================
// Misc.
// ============================================================

// Program

Program::Program () {}

void Program::add (Node node)
{
	body.push_back(node);
}

std::string Program::string ()
{
	std::string str = "Program { ";

	for (int i = 0; i < body.size(); i++)
	{
		str += body.at(i).string() + " ";
	}

	str += "}";

	return str;
}

// ============================================================
// Literals
// ============================================================

// Numeric Literal

NumericLiteral::NumericLiteral (double value)
{
	this->value = value;
}

std::string NumericLiteral::string ()
{
	return "NumericLiteral {" + to_string(value) + "}";
}

// String Literal

StringLiteral::StringLiteral (std::string value)
{
	this->value = value;
}

std::string StringLiteral::string ()
{
	return "StringLiteral {" + value + "}";
}

// Identifier

Ident::Ident (std::string value)
{
	this->value = value;
}

std::string Ident::string ()
{
	return "Ident {" + value + "}";
}

// Literal

Literal::Literal (std::string value)
{
	this->value = value;
}

std::string Literal::string ()
{
	return "Literal {" + value + "}";
}

// ============================================================
// Statements
// ============================================================

// ============================================================
// Expressions
// ============================================================

// Binary Expression

BinaryExpr::BinaryExpr (Node left, Token op, Node right)
{
	this->left = left;
	this->op = op;
	this->right = right;
}

std::string BinaryExpr::string ()
{
	return "BinaryExpr { " + left.string() + " " + op.value + " " + right.string() + " }";
}