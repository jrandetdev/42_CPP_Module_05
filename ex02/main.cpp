#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	DerivedClassConstruction();
void	DerivedClassConstructionWithTarget();

int main()
{
	DerivedClassConstruction();
	DerivedClassConstructionWithTarget();
	return (0);
}

void	DerivedClassConstruction()
{
	std::cout << YELLOW << "\nTest 1: Constructing basic derived classes" << RESET << '\n' << '\n';

	ShrubberyCreationForm Shrubtest;
	std::cout << YELLOW << Shrubtest << RESET << std::endl;

	std::cout << '\n';

	RobotomyRequestForm Robottest;
	std::cout << GREEN << Robottest << RESET << std::endl;

	std::cout << '\n';

	PresidentialPardonForm Presidentialtest;
	std::cout << BLUE << Presidentialtest << RESET << std::endl;

}

void	DerivedClassConstructionWithTarget()
{
	std::cout << YELLOW << "\nTest 2: Constructing basic derived classes" << RESET << '\n' << '\n';

	Bureaucrat Bob("Bob", 136);
	std::cout << '\n';
	ShrubberyCreationForm	ShrubForm("Home");

	Bob.executeForm(ShrubForm); 	// none of these shoukd work as the form is not signed

	Bob.signForm(ShrubForm);
	Bob.executeForm(ShrubForm);

	Bob.decrementBureaucratGrade();
	Bob.executeForm(ShrubForm);
}


