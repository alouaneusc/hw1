#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr list;

	
	list.push_front("fred");
	list.push_back("bob");
	
	// std::cout << list.size() << std::endl;
	std::cout << list.get(0) << std::endl;
	std::cout <<  list.get(1) <<std::endl;
	
}
