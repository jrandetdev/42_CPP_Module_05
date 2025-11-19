#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("Bob", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
