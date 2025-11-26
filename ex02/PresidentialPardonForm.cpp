#include "PresidentialPardonForm.hpp"

// Default constructor, calls the AForm constructor with arguments inside it
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}
