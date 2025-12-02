#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

void	GradeTooLowTest()
{
	printTestHeader("Test for all grades (Intern, CEO, boss with actions)", 1);
	printAction("Having intern make the form, then CEO sign form (with valid singing grade), and have the intern's boss execute the form (correct executing grade)");
	AForm *form = Intern().makeForm("robotomy request", "garden");
	try
	{
		Bureaucrat Alice("Alice", 73);
		Bureaucrat SomeRandomInternsBoss("Intern Manager", 44);
		Alice.signForm(*form);
		SomeRandomInternsBoss.executeForm(*form);
		//printSuccess();
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		//printFailure("Should not have thrown any exception!");
	}
}

void	InvalidFormNameTest()
{
	printTestHeader("Test for sending an invalid form name to the makeform() function", 2);
	printAction("Sending Rbtmy instead of robotomy request");	
	try
	{
		AForm *form = Intern().makeForm("Rbtmy", "villa");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printSuccess();
	}
}

void	ValidTest()
{
	printTestHeader("Test for all grades (Intern, CEO, boss with actions)", 1);
	printAction("Having intern make the form, then CEO sign form (with valid singing grade), and have the intern's boss execute the form (correct executing grade)");
	AForm *form = Intern().makeForm("robotomy request", "home");
	try
	{
		Bureaucrat Alice("Alice", 1);
		Bureaucrat SomeRandomInternsBoss("Intern Manager", 44);
		Alice.signForm(*form);
		SomeRandomInternsBoss.executeForm(*form);
		printSuccess();
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should not have thrown any exception!");
	}
}

int main()
{
	ValidTest();
	InvalidFormNameTest();
	GradeTooLowTest();
	return (0);
}
