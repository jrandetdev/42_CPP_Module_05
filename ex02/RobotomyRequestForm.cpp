#include "RobotomyRequestForm.hpp"

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
	
}
