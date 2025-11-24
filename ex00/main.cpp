#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Bureaucrat.hpp"

static void	constructorOfRangeGradesTest()
{
	std::cout << YELLOW << "Test 1: constructing with out of range grade (should not construct)" << RESET << std::endl;
	try
	{
		Bureaucrat test("Bob", 160);
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}

	try
	{
		Bureaucrat test2("Alice", 0);
	}
	catch(const std::exception& e)
	{	
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

static void incrementOutofRangeTest()
{
	std::cout << YELLOW << "\nTest 2: incrementing a grade and making it out of range" << RESET << std::endl;
	try
	{
		Bureaucrat test("Bob", 1);
		std::cout << GREEN << test << RESET << std::endl;
		test.incrementBureaucratGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

static void decrementOutofRangeTest()
{
	std::cout << YELLOW << "\nTest 3: decrementing a grade and making it out of range" << RESET << std::endl;
	try
	{
		Bureaucrat test("Bob", 1);
		std::cout << GREEN << test << RESET << std::endl;					// Generates the function call operator<<(cout, test)
		test.incrementBureaucratGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Exiting with exception" << '\n';
	}
}

static	void	correctValuesTest()
{
	std::cout << YELLOW << "\nTest 4: testing with correct values" << RESET << std::endl;
	try
	{
		Bureaucrat test("Charlie", 50);
		std::cout << GREEN << test << RESET << std::endl;
		test.incrementBureaucratGrade();
		std::cout << GREEN << test << RESET << std::endl;
		test.decrementBureaucratGrade();
		std::cout << GREEN << test << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	constructorOfRangeGradesTest();
	incrementOutofRangeTest();
	decrementOutofRangeTest();
	correctValuesTest();
	
	return (0);
}
