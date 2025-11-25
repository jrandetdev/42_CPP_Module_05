#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name("Shruberry Form"), _isSigned(false),
	_SigningGrade(145), _ExcecutingGrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	_name(other._name), _isSigned(other._isSigned), _SigningGrade(other._SigningGrade),
	_ExcecutingGrade(other._ExcecutingGrade) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
