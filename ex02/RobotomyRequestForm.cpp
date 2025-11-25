#include "RobotomyRequestForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("Shruberry Form"), _isSigned(false),
	_SigningGrade(72), _ExcecutingGrade(45) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	_name(other._name), _isSigned(other._isSigned), _SigningGrade(other._SigningGrade),
	_ExcecutingGrade(other._ExcecutingGrade) {}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
