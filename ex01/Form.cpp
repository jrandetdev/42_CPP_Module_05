#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <string>
#include <exception>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
Form::Form()
	: _name("Contract"), _isSigned(false), _minimumGradeSigning(10),
	_minimumGradeExecuting(10) {
}

//Constructor with arguments 
Form::Form (const std::string name, bool isSigned, \
	const int formSigningGrade, const int formExcecutingGrade)
	: _name(name), _isSigned(isSigned), _minimumGradeSigning(formSigningGrade),
	_minimumGradeExecuting(formExcecutingGrade)
{
	if (_minimumGradeSigning < 1)
		throw GradeTooHighException();
	if (_minimumGradeSigning > 150)
		throw GradeTooLowException();

	if (_minimumGradeExecuting < 1)
		throw GradeTooHighException();
	if (_minimumGradeExecuting > 150)
		throw GradeTooLowException();
}

//	Copy Constructor
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _minimumGradeSigning(other._minimumGradeSigning),
	_minimumGradeExecuting(other._minimumGradeExecuting) {}

// Copy Assignment Constructor
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

int			Form::getMinSigningGrade() const {
	return (this->_minimumGradeSigning);
}

int			Form::getMinExcecutingGrade() const {
	return (this->_minimumGradeExecuting);
}

// =============================================================================
// Exception Implementations
// =============================================================================

const char* Form::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* Form::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

// =============================================================================
// Member functions
// =============================================================================

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _minimumGradeSigning)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const Form& form)
{
	outstream << "\nForm name: " << form.getFormName() << '\n'
			<< "Form signature status: " << form.getFormSignatureStatus() << '\n'
			<< "Form grade required for executing: " << form.getMinExcecutingGrade() << '\n'
			<< "Form grade required for signing: " << form.getMinSigningGrade();
	return (outstream);
}
