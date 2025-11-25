#include "AForm.hpp"

// Constructor
AForm::AForm() : _name("Contract"), _isSigned(false), _SigningGrade(10),
	_ExecutingGrade(10) {}

//Constructor with arguments 
AForm::AForm (const std::string name, const int SigningGrade, const int ExecutingGrade
)
	: _name(name), _isSigned(false), _SigningGrade(SigningGrade),
	_ExecutingGrade(ExecutingGrade
	)
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

// Copy constructor
AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), 
	_SigningGrade(other._SigningGrade), _ExecutingGrade(other._ExecutingGrade) {}

// Copy assignment constructor (only non const are assigned as const is non assignable)
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

// Destructor
AForm::~AForm() {}
