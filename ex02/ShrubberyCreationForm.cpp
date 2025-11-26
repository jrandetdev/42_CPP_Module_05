#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137, "Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("Shrubbery Form", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// void	ShrubberyCreationForm::executeFormAction(void)
// {
// 	std::string	fileName;

// 	fileName = this->
// }
