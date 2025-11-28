#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

static void inBoundBureaucratSigning()
{
	std::cout << YELLOW << "\nTest 4: bureaucrat has enough grade to sign form" << RESET << '\n';
	try
	{
		Bureaucrat Bob("Bob", 50);
		std::cout << Bob << std::endl;

		Form contract("Contract", 100, 100);
		std::cout << contract << std::endl;

		Bob.signForm(contract);
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Exception caught: " << e.what() << '\n';
	}
}

static void	signingBureaucratLowGrade()
{
	std::cout << YELLOW << "\nTest 4: bureaucrat not high enough in grade to sign" << RESET << '\n';
	try
	{
		Bureaucrat Bob("Bob", 100);
		std::cout << Bob << std::endl;
		Form contract("Contract", 50, 50);
		std::cout << contract << std::endl;
		
		// Bob (grade 100) tries to sign a form requiring grade 50
		Bob.signForm(contract);
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Exception caught: " << e.what() << '\n';
	}
}

static void inBoundsConstruction()
{
	std::cout << YELLOW << "\nTest 3: constructing a form with a grade that is in bounds" << RESET << '\n';
	try
	{
		Form test("Contract", 1, 100);
		std::cout << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Exception caught: " << e.what() << '\n';
	}
}

static void	TooLowConstruction()
{
	std::cout << YELLOW << "\nTest 2: constructing a form with a grade that is too low" << RESET << '\n';
	try
	{
		Form test("Contract", 1, 151);
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "✗ Exception caught: " << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

static void	TooHighConstruction()
{
	std::cout << YELLOW << "Test 1: constructing a form with a grade that is too high" << RESET << '\n';
	try
	{
		Form test("Contract", 0, 100);
		std::cout << test << std::endl;
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

int main()
{
	TooHighConstruction();
	TooLowConstruction();
	inBoundsConstruction();
	signingBureaucratLowGrade();
	inBoundBureaucratSigning();
	return (0);
}
