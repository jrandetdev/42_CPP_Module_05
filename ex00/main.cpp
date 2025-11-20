#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Bureaucrat.hpp"

static void	constructorWithOutOfRangeGrades()
{
	try
	{
		Bureaucrat test("Bob", 160);
	}
	catch(const std::exception& e)
	{
		if (strcmp(e.what(), "Grade too low!") == 0) { std::cout << "\nTest 1 OK!" << std::endl; }
		
		std::cout << "Throwing GradeTooLowException ..." << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat test2("Alice", 0);
	}
	catch(const std::exception& e)
	{
		if (strcmp(e.what(), "Grade too high!") == 0) { std::cout << "\nTest 2 OK!" << std::endl; }
		
		std::cout << "Throwing GradeTooHighException ..." << std::endl;
		std::cerr << e.what() << '\n';
	}
}

static void incrementAndDecrement()
{
	try
	{
		Bureaucrat test("Bob", 50);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	constructorWithOutOfRangeGrades();
	incrementAndDecrement();
	return (0);
}
