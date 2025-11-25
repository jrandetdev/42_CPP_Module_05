# CPP05 - Exception Handling in C++

## Module Overview
This module focuses on understanding inheritance, getter/setter functions, and **exception handling with try-catch mechanisms**.

### Exercises
- **ex00:** Introduction to exceptions with try-catch
- **ex01:** Implementing specific behaviors for exceptions based on error types
- **ex02:** Combining abstract classes (from CPP04) with exception handling
- **ex03:** *(To be completed)*

---

## Key Concept: Exceptions

### What are Exceptions?
Exceptions provide a mechanism to transfer information from the point where an error is detected to a point where it can be handled (using `try` and `catch` blocks). While the standard library defines a hierarchy of exception classes (e.g., `bad_alloc`), this module requires defining custom exceptions.

### Advantages of Exception Handling
- **Program continuity:** Errors are caught and handled without terminating the program
- **Controlled termination:** Programs only terminate if explicitly instructed by the programmer
- **Graceful degradation:** Preferable to unconditional program termination (made explicit with `noexcept()` specifier)
- **Clear error signaling:** Exceptions communicate "some part of the system couldn't complete the requested operation"

### How Exceptions Work

**Throwing an exception:** Transfers control flow to an appropriate handler.

**Stack Unwinding Process:**
1. Creates an exception object with dynamic storage duration
2. Control flow moves backwards up the call stack until reaching the start of a `try` block
3. Parameters of all associated handlers are compared with the exception object's type
4. When a match is found, execution jumps to the corresponding handler
5. During unwinding, destructors are invoked for all automatic storage duration objects (in reverse order of construction)

**Reference:** [cppreference.com - throw](https://en.cppreference.com/w/cpp/language/throw)

**Example syntax:**
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

## ex00: Bureaucrat Class with Exceptions

### Objective
Create a `Bureaucrat` class that only exists when specific conditions are met.

### Class Requirements

**Attributes:**
- Constant name (initialized in initializer list)
- Grade ranging from **1** (highest) to **150** (lowest)
  - *Note: Lower numbers = higher rank (like company hierarchy)*

**Mandatory Functions:**
- Canonical form: constructor, destructor, copy constructor, copy assignment operator
- Grade manipulation: `incrementBureaucratGrade()` and `decrementBureaucratGrade()`
  - *Example: Incrementing grade 3 → grade 2*

**Exception Handling:**
Invalid grades must throw:
- `Bureaucrat::GradeTooHighException` (grade < 1)
- `Bureaucrat::GradeTooLowException` (grade > 150)

### Implementation
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

    // Nested exception classes (inherit from std::exception)
    class GradeTooHighException: public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

    // Getters
    const std::string&  getName(void) const;
    int                 getGrade(void) const;
    
    // Grade manipulation
    void                incrementBureaucratGrade();
    void                decrementBureaucratGrade(); 
};
```

### Key Learning
- **Custom exceptions:** Inherit from `std::exception` class
- **Overloaded insertion operator (`<<`):** Defined as a non-member function because:
  - Must take `std::ostream` on the left
  - Takes `Bureaucrat` reference on the right
  - Cannot be a member function (would require `this->` on the left side)

---

## ex01: Form Class

### Objective
Create a `Form` class that requires appropriate bureaucrat grades for signing and execution.

### Class Requirements

**Private Attributes** *(with corresponding getters):*
- Constant name
- Boolean `_isSigned` (defaults to `false` at construction)
- Constant grade required to sign (signing only possible if bureaucrat's grade is high enough)
- Constant grade required to execute (execution only possible if bureaucrat's grade is high enough)

**Grade Rules:**
- Same constraints as Bureaucrat (1-150 range with exceptions)

### Implementation
```cpp
class Form
{
    public:
        // Constructors and destructors
        Form();
        Form(const std::string name, bool _isSigned, \
            const int _formSigningGrade, const int _formExecutingGrade);
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
        const std::string&  getName() const;
        bool                getSignatureStatus() const;
        int                 getFormSigningGrade() const;
        int                 getFormExecutingGrade() const;

        // Member function
        void                beSigned(const Bureaucrat& bureaucrat);

    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _formSigningGrade;
        const int           _formExecutingGrade;
    };
```

The following member functions are specific to the Form class:
- beSigned() member function: it changes the form's _isSigned status if the grade is high enough (greater or equal to the required one in the Form class). If too low, throw a GradeTooLowException.

Learning: exceptions can be thrown anywhere in code. 

---

## ex02

Back to abstract classes for a refresher. A Virtual fucntions are made in the base class, in this case the AForm class which will then be inherited by all of its special form derived classes.
- An Abstract class which contains pure virtual functions (at least one) with = 0. 
- Pure virtual functions are not defined and need to be defined by the derived classes.
- Abstract classes cannot be instantiated
- Late binding or dynamic binding is performed when the virtual keyword is used in a method's declaration. C++ will create a virtual table, which is a lookup table for such functions that will always be consulted when they are called.
- An Abstract class ensures common structure to all derived classes

private members are not accessible by derived classes 
