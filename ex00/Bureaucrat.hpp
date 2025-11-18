#include <iostream>
#include <string>
#include <exception>

class GradeTooHighException : public exception
{
	const char* what() const throw();
};

class GradeTooLow : public exception
{
	const char* what() const throw();
};

/**
 * @brief Bureaucrat class contains
 * 
 * - A constand name
 * 
 * - A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade)
 * 
 * - Any attempt to instantiate a Bureaucrat wih an invalid grade must throw an exception
 * GradeTooHighException or GradeTooLowException
 * 
 * - getters are provided for both attributes (getName() and getGrade())
 * 
 * - Two member functions to increment and decrement the bureaucrat's grade are implemented.
 * 
 * @attention Grade 1 is the highest grade, and 150 is the lowest. SO incrementing a grade 3 -> 2.
 * 
 */
class	Bureaucrat
{
	private:
		std::string const	name;
		int 				grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException();

		// Pass by const reference
		const std::string& 	getName(void) const;
		int			getGrade(void) const;

		void				incrementBureaucratGrade();
		void				decrementBureaucratGrade();
};
