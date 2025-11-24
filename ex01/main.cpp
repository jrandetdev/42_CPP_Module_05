#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <string>
#include <exception>

static void inBoundsConstruction()
{
	std::cout << "\nTest 3 inBoundsConstruction" << '\n';
	try
	{
		Form test("Contract", false, 1, 100);
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

static void	TooLowConstruction()
{
	std::cout << "\nTest 2 OutOfRangeConstruction" << '\n';
	try
	{
		Form test("Contract", false, 1, 151);
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

static void	TooHighConstruction()
{
	std::cout << "\nTest 2 OutOfRangeConstruction" << '\n';
	try
	{
		Form test("Contract", false, 0, 100);
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

void	gettersTest()
{
	Form test;
	std::cout << test << std::endl;
}

int main()
{
	gettersTest();
	TooHighConstruction();
	TooLowConstruction();
	inBoundsConstruction();
	return (0);
}
