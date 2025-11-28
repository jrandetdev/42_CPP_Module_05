#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

// base class of the form class for ther other classes
class	AForm
{
	public:
		// Constructors and destructors
		AForm();
		AForm (const std::string name, const int formSigningGrade, const int formExcecutingGrade, const std::string &target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getFormName() const;                                                                                                                                                                                                                          
		bool				getFormSignatureStatus() const;
		int					getSigningGrade() const;
		int					getExecutingGrade() const;
		const std::string&	getTarget() const;

		virtual void		beSigned(const Bureaucrat& bureaucrat);
		virtual void 		execute(Bureaucrat const & executor) const; // calls the executeFormAction
		
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	protected:
		virtual void		executeFormAction(void) const = 0;
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_SigningGrade;
		const int 			_ExecutingGrade;
		const std::string	_target;
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
