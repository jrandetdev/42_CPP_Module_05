#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <string>
#include <exception>


static void inBoundBureaucratSigning()
{
	std::cout << YELLOW << "\nTest 4 signingBureaucratLowGrade" << RESET << '\n';
	try
    {
        Bureaucrat Bob("Bob", 50);
		std::cout << Bob << std::endl;

        Form contract("Contract", false, 100, 100);
        std::cout << contract << std::endl;

        // Bob (grade 100) tries to sign a form requiring grade 50
        Bob.signForm(contract);
    }
    catch(const std::exception& e)
    {
        std::cerr << "✗ Exception caught: " << e.what() << '\n';
    }
}

static void	signingBureaucratLowGrade()
{
	std::cout << YELLOW << "\nTest 4 signingBureaucratLowGrade" << RESET << '\n';
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
	std::cout << YELLOW << "\nTest 3 inBoundsConstruction" << RESET << '\n';
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
	std::cout << YELLOW << "\nTest 2 OutOfRangeConstruction" << RESET << '\n';
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
	std::cout << YELLOW << "\nTest 2 OutOfRangeConstruction" << RESET << '\n';
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
	inBoundBureaucratSigning();
	return (0);
}
