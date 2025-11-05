#include <iostream>
#include <string>

class	Bureaucrat
{
	private:
		std::string const	name;
		int 				grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		void				setName(std::string name) const;
		std::string 		getName(void) const;
		void				setGrade(int grade) const;
		int					getGrade(void) const;	
		void				incrementBureaucratGrade();
		void				decrementBureaucratGrade();
};
