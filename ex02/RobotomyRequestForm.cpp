#include "RobotomyRequestForm.hpp"


#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45, "Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("Robotomy Request Form", 72, 45, target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

// Copy assignment constructor
RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

// Destructpor
RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeFormAction(void)
{
	int random_number = 1 + ( std::rand() % ( 4 - 0 + 1 ) );
	std::cout << "Drilllllllliiiing noiiiiiiseeeeee" << '\n';
	if (random_number <= 2)
	{
		std::cout << getTarget() << " has been robotomized succesfully!" << '\n' << '\n';
	}
	else
	{
		std::cout << "The Robotomy for " << getTarget() << " failed...." << '\n' << '\n';
	}
}
