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
	
	Bureaucrat Alice("Alice", 1);
	Bureaucrat SomeRandomInternsBoss("Intern Manager", 44);
	Intern	SomeRandomIntern;
	AForm* 	rrf;
	
	rrf = SomeRandomIntern.makeForm("robotomy request", "Home");
	Alice.signForm(*rrf);
	SomeRandomInternsBoss.executeForm(*rrf);
	delete rrf;
	AForm*	scf;
	scf = SomeRandomIntern.makeForm("shrubbery creation", "Villa");
	delete scf;
}

