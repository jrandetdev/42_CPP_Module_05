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
	: _name("Contract"), _isSigned(false), _formSigningGrade(10),
	_formExecutingGrade(10) {
}

Form::Form (const std::string name, bool isSigned, \
	const int formSigningGrade, const int formExcecutingGrade)
	: _name(name), _isSigned(isSigned), _formSigningGrade(formSigningGrade),
	_formExecutingGrade(formExcecutingGrade) {
	if (_formSigningGrade < 1)
		throw GradeTooHighException();
	if (_formSigningGrade > 150)
		throw GradeTooLowException();

	if (_formExecutingGrade < 1)
		throw GradeTooHighException();
	if (_formExecutingGrade > 150)
		throw GradeTooLowException();
}

//	Copy Constructor
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _formSigningGrade(other._formSigningGrade),
	_formExecutingGrade(other._formExecutingGrade) {}


// Copy Assignment Constructor
Form& Form::operator=(const Form& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

// Destructor
Form::~Form() {
	std::cout << RED << "Form " << this->getName()
			<< " destroyed" << RESET << '\n';
}

// =============================================================================
// Accessors (Getters)
// =============================================================================

const std::string&	Form::getName() const {
	return (this->_name);
}

bool	Form::getSignatureStatus() const {
	return (this->_isSigned);
}

int			Form::getFormSigningGrade() const {
	return (this->_formSigningGrade);
}

int			Form::getFormExcecutingGrade() const {
	return (this->_formExecutingGrade);
}

// // =============================================================================
// // Grade Management
// // =============================================================================

// void	Bureaucrat::incrementBureaucratGrade() {
// 	std::cout << "Incrementing the Bureaucrat grade" << '\n';
// 	this->_grade--;
// 	if (this->_grade < 1)
// 		throw GradeTooHighException();
// }

// void	Bureaucrat::decrementBureaucratGrade() {
// 	this->_grade++;
// 	std::cout << "Decrementing the Bureaucrat grade" << '\n';
// 	if (this->_grade >= 150)
// 		throw GradeTooLowException();
// }

// =============================================================================
// Exception Implementations
// =============================================================================

const char* Form::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

const char* Form::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

// =============================================================================
// Member functions
// =============================================================================

// void				beSigned(const Bureaucrat& bureaucrat)
// {

// }

// =============================================================================
// Stream Operators
// =============================================================================

std::ostream& operator<<(std::ostream& outstream, const Form& form)
{
	outstream << "Form name: " << form.getName() << '\n'
			<< "Form signature status: " << form.getSignatureStatus() << '\n'
			<< "Form grade required for executing: " << form.getFormExcecutingGrade() << '\n'
			<< "Form grade required for signing: " << form.getFormSigningGrade();
	return (outstream);
}
