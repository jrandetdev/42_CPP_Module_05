#include "Bureaucrat.hpp"

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object with default values.
 */
Bureaucrat::Bureaucrat() : name("Bob"), grade(10)
{
	std::cout << "Bureaucrat:: default constructor called with basic values" << '\n';
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object with two parameters.
 * 
 * @attention when data members are declared as constant, they have to have some value before
 * the object is construted. Hence we use member intializer so that before the object is
 * constructed, that member has value. (stackoverflow). They cannto be intialised later
 * 
 * @param name 
 * @param grade 
 */
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade <= 1)
		throw 
	std::cout << "Bureaucrat:: own constructor which takes as parameters the name and grade" << '\n';
}

/**
 * @brief Copy Construct a new Bureaucrat:: Bureaucrat object
 * 
 * @param other (const reference to an existing object of the same class)
 * 
 */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : grade(other.grade)
{

}

/**
 * @brief Copy assignment constructor is called when an already initialised object is 
 * assigned a new value from another existing object.
 * 
 * @param other 
 * @return Bureaucrat& 
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string& Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const char* Bureaucrat::what() const throw()
{

}

void	Bureaucrat::incrementBureaucratGrade()
{
	this->grade--;
	if (this->grade <= 0)
		//throw the exception grade too high
}

void	Bureaucrat::decrementBureaucratGrade()
{
	this->grade++;
	if (this->grade >= 150)
		//throw the exception grade is too low
}
