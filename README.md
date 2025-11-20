# CPP05

## About this Module

The scope of this Module is to further understand inheritance, getter and setter functions and **more importantly the try-catch mechanisms with exceptions.**
**List of exercises:**
- **ex00:** Introduction to exceptions with try-catch
- **ex01:** Implement specific behaviours for exceptions according to the error caught
- **ex02:** Combine the knowledge gained in CPP04 with abstract classes and exceptions.
- **ex03:** to be written
---
## New concept: exceptions

**Exceptions:** An exception is provided to help get information from the point where an error is detected to a point where it can be handled (try, catch).
The standard library defines a small hierarchy of exception classes (bad_alloc etc.) but here we have to define our own exceptions.

**Advantage of exception handling:** 
- Instead of terminating the program when an error is handled, the errors are simply caught but the program can still run.
- An exception will terminate a program ONLY if the programmer decides it should.
- Preferable to the unconditional termination of programs. The noexcept() specifier makes that explicit.
- Exceptions mean "some part of the system couldn't do what I asked it to do"

**Throw concept:** The throw transfers control to a handler for exceptions of the type of exception you give it (in our case, GradeTooHighException or GradeTooLowException). To do that, the implementation will unwind the function call stack as needed to get back to the context of the caller. 
In our main.cpp, we put code for which we are interested in handling exceptions into a try-block. If it fails, the catch-clause providing a handler for the error will be entered. In our case, if the grade is out of range, we handle it accordingly. 

For example:
```cpp
try
{
    /* do some studff with bureaucrats */
}
catch (std::exception & e)
{
    /* handle exception */
}
```
---
## ex00

Goal of the exercise: create a Bureaucrat. A Bureaucrat has 
- a constant name (careful, needs to be initialised in the initializer list)
- a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade) - yes they are kind of inverted.
**Introduction to exceptions and try-catch:** in our program, Bureaucrats with an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

```cpp
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

		const std::string& 	getName(void) const;
		int			getGrade(void) const;

		void				incrementBureaucratGrade();
		void				decrementBureaucratGrade();	
};
```

It also contains two member functions to increment and decrement the fgrade. If the grade goes out of range, the program handles the exceptions just like in the construtor.
