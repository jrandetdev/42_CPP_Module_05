#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#ifndef COLORS
#define COLORS
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#endif

/**
 * @brief Bureaucrat with a name and grade (1-150).
 * 
 * Grade 1 is highest, 150 is lowest.
 * Throws GradeTooHighException or GradeTooLowException for invalid grades.
 */
class Bureaucrat
{
	public:
		// Constructors and destructor
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Getters
		const std::string&  getName() const;
		int                 getGrade() const;

		// Grade modification
		void incrementBureaucratGrade();
		void decrementBureaucratGrade();

	private:
		const std::string   _name;
		int                 _grade;
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
