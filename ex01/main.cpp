#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

static void printTestHeader(const std::string& testName, int testNum)
{
    std::cout << "\n" << BOLD << CYAN << "═══════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "TEST " << testNum << ": " << testName << RESET << std::endl;
    std::cout << BOLD << CYAN << "═══════════════════════════════════════" << RESET << std::endl;
}

static void printSuccess(const std::string& message = "Test passed")
{
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
}

static void printFailure(const std::string& message = "Test failed")
{
    std::cout << RED << "✗ " << message << RESET << std::endl;
}

static void printAction(const std::string& action)
{
    std::cout << BLUE << "→ " << action << RESET << std::endl;
}

static void inBoundBureaucratSigning()
{
	printTestHeader("Building a bureaucrat with a grade which is okay to sign the contract", 4);
	printAction("Building Bob with grade 100, and form has both signing and executing grade at 100.");
	try
	{
		Bureaucrat Bob("Bob", 50);
		std::cout << Bob << std::endl;

		Form contract("Contract", 100, 100);
		std::cout << contract << std::endl;

		Bob.signForm(contract);
		printSuccess();
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have signed the form!");
	}
}

static void	signingBureaucratLowGrade()
{
	printTestHeader("Building a bureaucrat with a grade which is too low to sign", 3);
	printAction("Building Bob with grade 100, and form has both signing and executing grade at 50 (Bob is too low).");
	try
	{
		Bureaucrat Bob("Bob", 100);
		std::cout << Bob << std::endl;
		Form contract("Contract", 50, 50);
		std::cout << contract << std::endl;
		
		// Bob (grade 100) tries to sign a form requiring grade 50
		Bob.signForm(contract);
		printSuccess();
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have thrown exception!");
	}
}

static void inBoundsConstruction()
{
	printTestHeader("Constructing a form both grades within the ranges", 3);
	printAction("Building a form with a signing grade of 1 and executing grade of 100.");
	try
	{
		Form test("Contract", 1, 100);
		std::cout << test << std::endl;
		printSuccess();
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have built the form!");
	}
}

static void	TooLowConstruction()
{
	printTestHeader("Constructing a form with an executing grade which is too low...", 2);
	printAction("Building a form with an executing grade of 151 (too low)...");
	try
	{
		Form test("Contract", 1, 151);
		std::cout << GREEN << test << RESET << std::endl;
		printFailure("Should have thrown exception!");
	}
	catch(const std::exception& e)
	{
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printSuccess();
	}
}

static void	formConstructorOutOfRange()
{
	printTestHeader("Constructor with Out-of-range form grade", 1);
	printAction("Attempting to create a form with a required grade of 0 for signing the form (too high)...");
	try
	{
		Form test("Contract", 0, 100);
		std::cout << GREEN << test << RESET << std::endl;
		printFailure("Should have thrown exception!");
	}
	catch(const std::exception& e)
	{
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printSuccess();
	}
}

int main()
{
	formConstructorOutOfRange();
	TooLowConstruction();
	inBoundsConstruction();
	signingBureaucratLowGrade();
	inBoundBureaucratSigning();
	return (0);
}
