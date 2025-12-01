#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define PRESIDENT_PARDON "presidential pardon"
#define ROBOTOMY_REQUEST "robotomy request"
#define SHRUBBERRY_CREATION "shrubbery creation"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm*	makeForm(const std::string& name, const std::string& target);
		AForm* (*creators[3])(const std::string& target);
		static AForm* newShrubbery(const std::string& target);
		static AForm* newRobotomy(const std::string& target);
		static AForm* newPresidentialPardon(const std::string& target);
		class FormNameNotFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

#endif
