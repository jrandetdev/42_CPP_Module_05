#include "Intern.hpp"

#include <iostream>
#include <string>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

Intern::Intern() {
	creators[0] = &newShrubbery;
	creators[1] = &newRobotomy;
	creators[2] = &newPresidentialPardon;
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {
	std::cout << RED << "Intern destroyed." << RESET << std::endl;
}

// =============================================================================
// Member functions
// =============================================================================

AForm* Intern::newShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

AForm* Intern::newRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }

AForm* Intern::newPresidentialPardon(const std::string& target) { return new PresidentialPardonForm(target); }


AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string form_names[3] = {SHRUBBERRY_CREATION, ROBOTOMY_REQUEST, PRESIDENT_PARDON};
	
	for (int i = 0; i < 3 ; ++i) {
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (creators[i](target));
		}
	}
	throw FormNameNotFound();	
	return (NULL);
}

const char* Intern::FormNameNotFound::what() const throw() {
	return ("Exception: Form Name not found!");
}
