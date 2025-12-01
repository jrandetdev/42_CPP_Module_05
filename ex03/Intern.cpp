#include "Intern.hpp"

#include <iostream>
#include <string>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() { std::cout << RED << "Intern destroyed." << RESET << std::endl; }

// =============================================================================
// Member functions
// =============================================================================

static AForm* Intern::newShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

static AForm* Intern::newRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }

static AForm* Intern::newPresidentialPardon(const std::string& target) { return new PresidentialPardonForm(target); }


AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string form_names[3] = {SHRUBBERRY_CREATION, ROBOTOMY_REQUEST, PRESIDENT_PARDON};
	AForm* (Intern::*creators[3])(const std::string&) = {
		&newPresidentialPardon, &Intern::newRobotomy, &Intern::newShrubbery};
	// int i;
	// for (i = 0; i < 3 && name != form_names[i]; ++i) { }
	// switch (i)
	// {
	// 	case SHRUBBERY:
	// 	{
	// 		std::cout << "Intern creates " << name << " form." << std::endl;
	// 		return new ShrubberyCreationForm(target);
	// 	}
	// 	case ROBOTOMY:
	// 	{
	// 		std::cout << "Intern creates " << name << " form." << std::endl;
	// 		return new RobotomyRequestForm(target);
	// 	}
	// 	case PRESIDENTIAL:
	// 	{
	// 		std::cout << "Intern creates " << name << " form." << std::endl;
	// 		return new PresidentialPardonForm(target);
	// 	}
	// 	default:
	// 		std::cout << "Error! The form name is incorrect. It must be one of the following:\n" \
	// 		<< "- " << SHRUBBERRY_CREATION << "\n" \
	// 		<< "- " << ROBOTOMY_REQUEST << "\n" \
	// 		<< "- " PRESIDENT_PARDON  << '\n' << std::endl;
	// }
	return (NULL);
}



