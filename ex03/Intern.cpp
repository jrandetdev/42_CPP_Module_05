#include "Intern.hpp"

#include <iostream>
#include <string>


Intern::Intern() { std::cout << "Intern created." << std::endl; }

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() { std::cout << "Intern destroyed." << std::endl; }

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string form_names[3] = {SHRUBBERRY_CREATION, ROBOTOMY_REQUEST, PRESIDENT_PARDON};
	int i;
	for (i = 0; i < 3 && name != form_names[i]; ++i) { }
	switch (i)
	{
		case SHRUBBERY:
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case ROBOTOMY:
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return new RobotomyRequestForm(target);
		}
		case PRESIDENTIAL:
		{
			std::cout << "Intern creates " << name << " form." << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
			std::cout << "Error! The form name is incorrect. It must be " << SHRUBBERRY_CREATION << ", " \
			<< ROBOTOMY_REQUEST << ", or " << PRESIDENT_PARDON << "." << std::endl;
	}
	return (NULL);
}
