#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	ValidTest();

int main()
{
	ValidTest();
	return (0);
}

void	ValidTest()
{
	std::cout << YELLOW << "\nTest 1: Intern creates three forms and executes them" << RESET << '\n' << '\n';
	
	AForm *form = Intern().makeForm("robotomy request", "home");
	try
	{
		Bureaucrat Alice("Alice", 1);
		Bureaucrat SomeRandomInternsBoss("Intern Manager", 44);
		Alice.signForm(*form);
		SomeRandomInternsBoss.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		delete form;
		std::cerr << e.what() << '\n';
	}
}

