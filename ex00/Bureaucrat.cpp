#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : grade(other.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{

}

void	Bureaucrat::incrementBureaucratGrade()
{
	if ((grade + 1) > 150)
		throw std:://out_of_range() I have to make my own exception
}
