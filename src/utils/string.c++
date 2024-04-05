// #include <iostream>
#include "string.h"

bool ustr_find (std::string str, std::string substr)
{
	int i = -1;
	int len = substr.size();

	while (str[++i])
	{
		// std::cout << str.substr(i, len) << "\n";
		if (str.substr(i, len) == substr)
		{
			return true;
		}
	}

	return false;
}

bool ustr_find (std::string str, char substr)
{
	int i = -1;

	while (str[i++])
	{
		if (str[i] == substr)
		{
			return true;
		}
	}

	return false;
}