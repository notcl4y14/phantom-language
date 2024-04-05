// #include <iostream>
#include "arr.h"

bool uarr_find (std::string arr[], std::string str)
{
	int i = -1;

	while ( i++ && i <= (sizeof(arr) / sizeof(arr[0])) )
	{
		if (arr[i] == str)
		{
			return true;
		}
	}

	return false;
}

bool uarr_find (std::vector<std::string> arr, std::string str)
{
	int i = -1;

	// std::cout << arr.size() << "\n";
	
	while ( i++ || i < arr.size() )
	{
		// std::cout << i << "; " << arr.at(i) << " == " << str << "\n";
		if (arr.at(i) == str)
		{
			return true;
		}
	}

	return false;
}