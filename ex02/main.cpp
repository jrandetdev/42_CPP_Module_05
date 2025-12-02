#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void	GradeTooLowForExecuting()
{
	printTestHeader("Testing with bureaucrat too low to execute grade", 3);
	printAction("Setting executing grade lower than the one for the form");
	try
	{
		RobotomyRequestForm Rob("Villa");
		Bureaucrat Bob("Bob", 46);
		Bob.signForm(Rob);
		std::cout << "Program should continue and attempt to execute the form..." << '\n';
		Bob.executeForm(Rob);
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have built all three derived classes");
	}
}

void	DerivedClassConstructionWithTarget()
{
	printTestHeader("Trying to execute a form that is not signed, then signing it and executing it (should continue program despite first exception)", 2);
	printAction("Calling executeForm before calling signForm, then calling signForm and then executeForm");
	try
	{
		Bureaucrat Bob("Bob", 130);
		ShrubberyCreationForm	ShrubForm("Home");
		Bob.executeForm(ShrubForm);
		std::cout << "Test should keep running, exception is just caught by executeForm!" << '\n';
		Bob.signForm(ShrubForm);
		Bob.executeForm(ShrubForm);
		printSuccess();
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have continued the program since executeForm had to catch");
	}
}

void	DerivedClassConstruction()
{
	printTestHeader("Testing correct construction", 1);
	printAction("Constructing all three derived classes and testing the output.");
	try
	{
		ShrubberyCreationForm Shrubtest;
		std::cout << YELLOW << Shrubtest << RESET << std::endl;
		RobotomyRequestForm Robottest;
		std::cout << GREEN << Robottest << RESET << std::endl;
		PresidentialPardonForm Presidentialtest;
		std::cout << BLUE << Presidentialtest << RESET << std::endl;
		printSuccess();
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
		printFailure("Should have built all three derived classes");
	}
}

int main()
{
	DerivedClassConstruction();
	DerivedClassConstructionWithTarget();
	GradeTooLowForExecuting();
	return (0);
}
