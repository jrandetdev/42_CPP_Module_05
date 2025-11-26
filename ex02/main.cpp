#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	DerivedClassConstruction()
{
	std::cout << YELLOW << "\nTest 1: Creating the different forms with their specifics" << RESET << '\n' << '\n';

	ShrubberyCreationForm Shrubtest;
	std::cout << YELLOW << Shrubtest << RESET << std::endl;

	std::cout << '\n';

	RobotomyRequestForm Robottest;
	std::cout << GREEN << Robottest << RESET << std::endl;

	std::cout << '\n';

	PresidentialPardonForm Presidentialtest;
	std::cout << BLUE << Presidentialtest << RESET << std::endl;

}

int main()
{
	DerivedClassConstruction();
}
