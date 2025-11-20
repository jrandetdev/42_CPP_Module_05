# CPP05
## About this Module
The scope of this Module is to further understand inheritance, getter and setter functions and **more importantly the try-catch mechanisms with exceptions.**

**List of exercises:**
- **ex00:** Introduction to exceptions with try-catch
- **ex01:** Implement specific behaviours for exceptions according to the error caught
- **ex02:** Combine the knowledge gained in CPP04 with abstract classes and exceptions.
- **ex03:** to be written

---

## New Concept: Exceptions
**Exceptions:** An exception is provided to help get information from the point where an error is detected to a point where it can be handled (try, catch). The standard library defines a small hierarchy of exception classes (bad_alloc etc.) but here we have to define our own exceptions.

**Advantage of exception handling:** 
- Instead of terminating the program when an error is handled, the errors are simply caught but the program can still run.
- An exception will terminate a program ONLY if the programmer decides it should.
- Preferable to the unconditional termination of programs. The noexcept() specifier makes that explicit.
- Exceptions mean "some part of the system couldn't do what I asked it to do"

**Throw concept:** The throw transfers control to a handler for exceptions of the type of exception you give it (in our case, GradeTooHighException or GradeTooLowException). To do that, the implementation will unwind the function call stack as needed to get back to the context of the caller. 

For example:
```cpp
try
{
    /* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
    /* handle exception */
}
```

---

## ex00
Goal of the exercise: create a Bureaucrat which exists only if a couple of conditions are met...

A Bureaucrat has:
- The Canonical constructor/destructor, copy constructor, copy assignment operator
- A constant name (careful, needs to be initialised in the initializer list)
- A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade) - yes they are kind of inverted.
- The two exceptions as inline classes
- Increment and decrement member functions

**Introduction to exceptions and try-catch:** in our program, Bureaucrats with an invalid grade must either throw the Bureaucrat::GradeTooHighException or Bureaucrat::GradeTooLowException.

```cpp
class Bureaucrat
{
private:
    std::string const   _name;
    int                 _grade;

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

    const std::string&  getName(void) const;
    int                 getGrade(void) const;
    void                incrementBureaucratGrade();
    void                decrementBureaucratGrade(); 
};
```

The insert operator is overloaded but it is defined as a non-member function because it must take the std::ostream on the left (a) of it and a reference to a Bureaucrat object on its right (b). 
a.operator<<(b). We cannot have it inside our class and use this->.

---
