#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
AForm::AForm() : _name("Contract"), _isSigned(false), _SigningGrade(10),
	_ExecutingGrade(10), _target("default target")
{
	std::cout << "AForm base class constructed" << std::endl;
}

//Constructor with arguments 
AForm::AForm (const std::string name, const int formSigningGrade, const int formExcecutingGrade, const std::string &target)
	: _name(name), _isSigned(false), _SigningGrade(formSigningGrade),
	_ExecutingGrade(formExcecutingGrade), _target(target)
{
	if (_SigningGrade < 1)
		throw GradeTooHighException();
	if (_SigningGrade > 150)
		throw GradeTooLowException();

	if (_ExecutingGrade < 1)
		throw GradeTooHighException();
	if (_ExecutingGrade > 150)
		throw GradeTooLowException();

	std::cout << "AForm base class constructed" << std::endl;
}

//	Copy Constructor
AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _SigningGrade(other._SigningGrade),
	_ExecutingGrade(other._ExecutingGrade), _target(other._target) {}

// Copy Assignment Constructor (only _isSigned can be changed)
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this); 
}

// Destructor
AForm::~AForm()
{
	std::cout << RED << "Form " << this->getFormName()
			<< " destroyed" << RESET << '\n';
}

// =============================================================================
// Accessors (Getters)
// =============================================================================

const std::string&	AForm::getFormName() const
{
	return (this->_name);
}

bool	AForm::getFormSignatureStatus() const
{
	return (this->_isSigned);
}

int	AForm::getSigningGrade() const { return (this->_SigningGrade); }

int	AForm::getExecutingGrade() const { return (this->_ExecutingGrade); }

const std::string &AForm::getTarget() const { return (this->_target); }

// =============================================================================
// Exception Implementations
// =============================================================================

const char* AForm::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

const char* AForm::FormNotSignedException::what() const throw() { return ("Exeption: Form is not signed!"); }


// =============================================================================
// Member functions
// =============================================================================

// Check against the minimum required and throws an exception if not
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _SigningGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned)
	{
		if (executor.getGrade() <= _ExecutingGrade)
		{
			this->executeFormAction();
		}
		else
		{
			throw Bureaucrat::GradeTooLowException();
		}
	}
	else
	{
		throw AForm::FormNotSignedException();
	}
}

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const AForm& form)
{
	outstream << "Form name: " << form.getFormName() << '\n'
			<< "Form signature status: " << form.getFormSignatureStatus() << '\n'
			<< "Form grade required for executing: " << form.getExecutingGrade() << '\n'
			<< "Form grade required for signing: " << form.getSigningGrade() << '\n'
			<< "Target: " << form.getTarget() << '\n';
	return (outstream);
}
