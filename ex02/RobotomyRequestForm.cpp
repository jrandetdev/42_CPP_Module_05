#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45) {}

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
