#include "Bureaucrat.hpp"

/// CONSTRUCTORS ///

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object with default values.
 */
Bureaucrat::Bureaucrat() : _name("Bob"), _grade(10)
{
	std::cout << "Bureaucrat:: default constructor called with basic values" << '\n';
}

/**
 * @brief Construct a new Bureaucrat:: object with two parameters.
 * 
 * @attention when data members are declared as constant, they cannot be left
 * uninitialised and must be initialised before the construct part of the code
 * is executed. 
 * 
 * @param name 
 * @param grade 
 */
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat:: own constructor which takes as parameters the name and grade" << '\n';
}


/// COPY CONSTRUCTOR ///

/**
 * @brief Copy Construct a new Bureaucrat:: Bureaucrat object. It creates a new object and does 
 * not need to clean up old data. It can be called during initialisation. 
 * 
 * MyClass obj1(5);           // Constructor
 * 
 * MyClass obj2 = obj1;       // Copy constructor (initialization)
 * 
 * MyClass obj3(3);           // Constructor
 * 
 * obj3 = obj1;               // Copy assignment (both already exist)
 * 
 * @param other (const reference to an existing object of the same class)
 * 
 */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{

}


///	COPY ASSIGNMENT CONSTRUCTOR ///

/**
 * @brief Copy assignment constructor is called with = between two existing objects.
 * 
 * @param other 
 * @return Bureaucrat& 
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

/// DESTRUCTOR ///

/**
 * @brief Destroy the Bureaucrat:: object
 * 
 */
Bureaucrat::~Bureaucrat()
{

}

/// GETTERS ///

/**
 * @brief accesses the private attribute name
 * 
 * @return const std::string& 
 */
const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/**
 * @brief An exception 
 * 
 * @return const char* 
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void	Bureaucrat::incrementBureaucratGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementBureaucratGrade()
{
	this->_grade++;
	if (this->_grade >= 150)
		throw GradeTooLowException();
}

/**
 * @brief Overload of the insertion operator. In C++11, we would declare it as a friend
 * because it would be called without creating an object. iN C++98 Since they take the
 * user-defined type as the right argument (b in a @ b), they must be implemented as non-members. 
 * 
 * @param outstream 
 * @param x (Bureaucrat object sent as a reference.)
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& outstream, const Bureaucrat& x)
{
	// write the desired input to the outstream
	outstream << x.getName() << ", bureaucrat grade" << x.getGrade();
	return (outstream);
}
