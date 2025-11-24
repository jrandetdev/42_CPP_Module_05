#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <string>
#include <exception>



void	checkOutOfRangeFormGrades(Form& form)
{
		if (form.getFormSigningGrade() < 1)
			throw Form::GradeTooHighException();
		else if (form.getFormSigningGrade() > 150)
			throw Form::GradeTooLowException();
		if (form.getFormExcecutingGrade() < 1)
			throw Form::GradeTooHighException();
		else if (form.getFormExcecutingGrade() > 150)
			throw Form::GradeTooLowException();
}

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

//	Default constructor
Form::Form()
	: _name("Contract"), _isSigned(false), _formSigningGrade(10),
	_formExecutingGrade(10) {
	checkOutOfRangeFormGrades(*this);
}

Form::Form (const std::string name, bool isSigned, \
	const int formSigningGrade, const int formExcecutingGrade)
	: _name(name), _isSigned(false), _formSigningGrade(formSigningGrade),
	_formExecutingGrade(formExcecutingGrade)
{

}

// //	Copy Constructor
// Bureaucrat::Bureaucrat(const Bureaucrat& other)
// 	: _name(other._name), _grade(other._grade) {}


// //	Copy Assignment Operator
// Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
// 	if (this == &other)
// 		return (*this);
// 	this->_grade = other._grade;
// 	return (*this);
// }

// // Destructor
// Bureaucrat::~Bureaucrat() {
// 	std::cout << RED << "Bureaucrat " << this->getName()
// 			<< " destroyed" << RESET << '\n';
// }

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

// // =============================================================================
// // Exception Implementations
// // =============================================================================

// const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Exeption: Grade too high!"); }

// const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Exception: Grade too low!"); }

// =============================================================================
// Member functions
// =============================================================================

void				beSigned(const Bureaucrat& bureaucrat)
{

}

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
