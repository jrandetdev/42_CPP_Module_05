#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iomanip>
#include <string>
#include <exception>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
AForm::AForm() : _name("Contract"), _isSigned(false), _SigningGrade(10),
	_ExecutingGrade(10) {}

//Constructor with arguments 
AForm::AForm (const std::string name, const int formSigningGrade, const int formExcecutingGrade)
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
AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _SigningGrade(other._SigningGrade),
	_ExecutingGrade(other._ExecutingGrade) {}

// Copy Assignment Constructor (only _isSigned can be changed)
AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this); 
}

// Destructor
AForm::~AForm() {
	std::cout << RED << "Form " << this->getFormName()
			<< " destroyed" << RESET << '\n';
}

// =============================================================================
// Accessors (Getters)
// =============================================================================

const std::string&	AForm::getFormName() const {
	return (this->_name);
}

bool	AForm::getFormSignatureStatus() const {
	return (this->_isSigned);
}

int	AForm::getSigningGrade() const {
	return (this->_SigningGrade);
}

int	AForm::getExecutingGrade() const {
	return (this->_ExecutingGrade);
}

// =============================================================================
// Exception Implementations
// =============================================================================

const char* AForm::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

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

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const AForm& form)
{
	outstream << "Form name: " << form.getFormName() << '\n'
			<< "Form signature status: " << form.getFormSignatureStatus() << '\n'
			<< "Form grade required for executing: " << form.getExecutingGrade() << '\n'
			<< "Form grade required for signing: " << form.getSigningGrade();
	return (outstream);
}
