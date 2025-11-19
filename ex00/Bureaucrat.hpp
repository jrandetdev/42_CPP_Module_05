#include <iostream>
#include <string>
#include <exception>

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
		std::string const	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

		// Pass by const reference
		const std::string& 	getName(void) const;
		int			getGrade(void) const;

		void				incrementBureaucratGrade();
		void				decrementBureaucratGrade();	
};

std::ostream& operator<<(std::ostream &outstream, const Bureaucrat &x);