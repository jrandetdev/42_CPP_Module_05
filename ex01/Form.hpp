#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iomanip>
#include <exception>

/**
 * @brief Form with a name, a boolean which states whether it has
 * been signed or not, two separate grades (both from1-150) needed for signing
 * the form and executing the form, respectively.
 * 
 * Throws GradeTooHighException and GradeTooLowException for invalid form
 * grades if out of bounds.
 * 
 */
class	Form
{
	public:
		// Constructors and destructors
		Form();
		Form (const std::string name, bool _isSigned, \
			const int _formSigningGrade, const int _formExcecutingGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

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
		const std::string&	getFormName() const;                                                                                                                                                                                                                          
		bool				getFormSignatureStatus() const;
		int					getFormSigningGrade() const;
		int					getFormExcecutingGrade() const;

		// // Member function
		void			beSigned(const Bureaucrat& bureaucrat);
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_formSigningGrade;
		const int 			_formExecutingGrade;
};

class Bureaucrat;

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
