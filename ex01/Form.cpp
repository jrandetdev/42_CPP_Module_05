#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>
#include <exception>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
Form::Form()
	: _name("Contract"), _isSigned(false), _SigningGrade(10),
	_ExecutingGrade(10) {}

//Constructor with arguments 
Form::Form (const std::string name, const int formSigningGrade, const int formExcecutingGrade)
	: _name(name), _isSigned(false), _SigningGrade(formSigningGrade),
	_ExecutingGrade(formExcecutingGrade)
{
	if (_SigningGrade < 1)
		throw GradeTooHighException();
	if (_SigningGrade > 150)
		throw GradeTooLowException();

	if (_ExecutingGrade < 1)
		throw GradeTooHighException();
	if (_ExecutingGrade > 150)
		throw GradeTooLowException();
}

//	Copy Constructor
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _SigningGrade(other._SigningGrade),
	_ExecutingGrade(other._ExecutingGrade) {}

// Copy Assignment Constructor (only _isSigned can be changed)
Form& Form::operator=(const Form& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this); 
}

// Destructor
Form::~Form() {
	std::cout << RED << "Form " << this->getFormName()
			<< " destroyed" << RESET << '\n';
}

// =============================================================================
// Accessors (Getters)
// =============================================================================

const std::string&	Form::getFormName() const {
	return (this->_name);
}

bool	Form::getFormSignatureStatus() const {
	return (this->_isSigned);
}

int	Form::getSigningGrade() const {
	return (this->_SigningGrade);
}

int	Form::getExecutingGrade() const {
	return (this->_ExecutingGrade);
}

// =============================================================================
// Exception Implementations
// =============================================================================

const char* Form::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* Form::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

// =============================================================================
// Member functions
// =============================================================================

// Check against the minimum required and throws an exception if not
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _SigningGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const Form& form)
{
	outstream << "Form name: " << form.getFormName() << '\n'
			<< "Form signature status: " << form.getFormSignatureStatus() << '\n'
			<< "Form grade required for executing: " << form.getExecutingGrade() << '\n'
			<< "Form grade required for signing: " << form.getSigningGrade();
	return (outstream);
}
