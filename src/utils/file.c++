#include <iostream>
#include "file.h"

std::string ufile_read (std::string filename)
{
	// https://stackoverflow.com/a/13035743
	std::ifstream file;
	file.open(filename);

	std::string output;
	std::string line;

	while (std::getline(file, line))
	{
		output += line + "\n";
	}

	file.close();
	return output;
}