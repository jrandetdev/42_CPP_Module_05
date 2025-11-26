#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
