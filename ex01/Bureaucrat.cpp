#include "Bureaucrat.hpp"
#include <iomanip>
#include <string>
#include <exception>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
Bureaucrat::Bureaucrat() : _name("Bob"), _grade(10) {}

//	Parametrised constructor
Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade) 
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

//	Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}


//	Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat " << this->getName()
			<< " destroyed" << RESET << '\n';
}

// =============================================================================
// Accessors (Getters)
// =============================================================================

const std::string& Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// =============================================================================
// Grade Management
// =============================================================================

void	Bureaucrat::incrementBureaucratGrade() {
	std::cout << "Incrementing the Bureaucrat grade" << '\n';
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementBureaucratGrade() {
	this->_grade++;
	std::cout << "Decrementing the Bureaucrat grade" << '\n';
	if (this->_grade > 150)
		throw GradeTooLowException();
}

// =============================================================================
// Exception Implementations
// =============================================================================

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const Bureaucrat& bureaucrat)
{
	outstream << bureaucrat.getName() << ", bureaucrat grade "
			<< bureaucrat.getGrade() << ".";
	return (outstream);
}
