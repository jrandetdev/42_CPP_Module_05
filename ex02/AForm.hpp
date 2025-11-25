#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iomanip>
#include <exception>


// base class of the form class for ther other classes
class	AForm
{
	public:
		// Constructors and destructors
		AForm();
		AForm (const std::string name, bool _isSigned, \
			const int _minimumGradeSigning, const int _AFormExcecutingGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

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
		
		// Getters const std::string&	getFormName() const;                                                                                                                                                                                                                          
		bool				getFormSignatureStatus() const;
		int					getMinSigningGrade() const;
		int					getMinExcecutingGrade() const;

		// // Member function
		virtual void		beSigned(const Bureaucrat& bureaucrat) = 0;
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_minimumGradeSigning;
		const int 			_minimumGradeExecuting;
};

class Bureaucrat;

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif