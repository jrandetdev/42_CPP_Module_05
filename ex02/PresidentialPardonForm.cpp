#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("Shruberry Form"), _isSigned(false),
	_SigningGrade(25), _ExcecutingGrade(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{

}

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
