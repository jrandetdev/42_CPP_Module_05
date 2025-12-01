#include "PresidentialPardonForm.hpp"

// Default constructor, calls the AForm constructor with arguments inside it
PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5, "Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 25, 5, target) {
	std::cout << *this << '\n';
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

// Copy Assignment constructor
PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::executeFormAction(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
