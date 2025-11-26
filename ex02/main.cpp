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
	std::cout << YELLOW << "\nTest 2: Constructing forms with target" << RESET << '\n' << '\n';

	std::string target;

	target = "Home";
	ShrubberyCreationForm Shrubtest(target);
	std::cout << YELLOW << Shrubtest << RESET << std::endl;

	std::cout << '\n';

	target = "Villa";
	RobotomyRequestForm Robottest(target);
	std::cout << GREEN << Robottest << RESET << std::endl;

	std::cout << '\n';

	target = "Chalet";
	PresidentialPardonForm Presidentialtest(target);
	std::cout << BLUE << Presidentialtest << RESET << std::endl;
	

}

int main()
{
	DerivedClassConstruction();
	DerivedClassConstructionWithTarget();
	return (0);
}
