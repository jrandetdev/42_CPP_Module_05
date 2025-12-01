#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	InvalidFormTest();

int main()
{
	InvalidFormTest();
	return (0);
}

void	InvalidFormTest()
{
	Intern	SomeRandomIntern;
	AForm* rrf;
	
	rrf = SomeRandomIntern.makeForm("robotomy request", "Home");
	std::cout << "robotomy request" << rrf << '\n';
	delete rrf;
	rrf = SomeRandomIntern.makeForm("ribdenwk", "Home");
	std::cout << "wrong ptr " << rrf << '\n';

	delete rrf;
}

