#include "RobotomyRequestForm.hpp"


#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45, "Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45, target) {
	std::cout << *this << '\n';
}

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

void	RobotomyRequestForm::executeFormAction(void) const
{
	std::srand(std::time(0));

    const int random_value = 1 + (std::rand() % ( 4 - 0 + 1 ));
	std::cout << "Drilllllllliiiing noiiiiiiseeeeee" << '\n';
	if (random_value <= 2)
	{
		std::cout << getTarget() << " has been robotomized succesfully!" << '\n' << '\n';
	}
	else
	{
		std::cout << "The Robotomy for " << getTarget() << " failed...." << '\n' << '\n';
	}
}
