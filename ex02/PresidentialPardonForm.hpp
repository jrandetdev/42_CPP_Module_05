#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

// virtzual base class, the most derived implementation will be executed

class	PresidentialPardonForm : public AForm
{
	void		beSigned(const Bureaucrat& bureaucrat);
}


#endif