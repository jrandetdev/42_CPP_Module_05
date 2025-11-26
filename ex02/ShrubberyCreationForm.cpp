#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137) {}

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
