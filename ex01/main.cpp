#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <string>
#include <exception>

static void	signingBureaucratLowGrade()
{
	std::cout << "\nTest 4 signingBureaucratLowGrade" << '\n';
	try
    {
        Bureaucrat Bob("Bob", 100);
        Form contract("Contract", false, 50, 50);
        
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


int main()
{
	TooHighConstruction();
	TooLowConstruction();
	inBoundsConstruction();
	signingBureaucratLowGrade();
	return (0);
}
