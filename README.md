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

**Throw concept:** throwing an exception transfers the control to a handler.

**Stack unwinding:**
1. It initialises an object with dynamic storage duration called the exception object.
2. Once the exception object is constructed, the control flow works backwards up the call stack until it reaches the start of a try block, at which point the parameters of all associated handlers are compared with the type of the exception object.
3. If it matches, it jumps to the coresponding handler.
4. As the control flow moves up the call stack, destructors are invoked for all objects with automati storage duration, but not yet destroyed since the corresponding try block was entered in reverse order of completion of their constructor.

see https://en.cppreference.com/w/cpp/language/throw.html 

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
- Increment and decrement member functions: incrementing a grade 3 results in a grade 2.

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

Exceptions that are created inherit from the std::exception class.

The insert operator is overloaded but it is defined as a non-member function because it must take the std::ostream on the left (a) of it and a reference to a Bureaucrat object on its right (b). 
a.operator<<(b). We cannot have it inside our class and use this->.

---

