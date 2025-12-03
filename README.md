# CPP05 - Exception Handling in C++

## Module Overview
This module focuses on understanding inheritance, getter/setter functions, and **exception handling with try-catch mechanisms**.

### Exercises
- **ex00:** Introduction to exceptions with try-catch
- **ex01:** Implementing specific behaviors for exceptions based on the class type which throws the exception (form/bureaucrat) 
- **ex02:** Combining abstract classes (from CPP04) with exception handling and inheritance, first example of a try-catch block being used within the code while the program continues running
- **ex03:** A more complete exercise where multiple actions overlap and the correct exception must be thrown at the right time

---

## Key Concept: Exceptions

### What are Exceptions?
Exceptions provide a mechanism to transfer information from the point where an error is detected to a point where it can be handled (using `try` and `catch` blocks). If there is no issue, the catch block is skipped. While the standard library defines a hierarchy of exception classes (e.g., `bad_alloc`), this module requires defining custom exceptions ("GradeTooLow", "GradeTooHigh", "FormNotSigned", etc.)

**Important:** The type of the parameter accepted by the catch block is crucial. It will only execute if it has the correct type. A chain of catch expressions can be used, each one with a different parameter type. Only the handler whose argument type matches the type of the exception specified in the throw statement is executed.

**std::exception:** std provides a base class specifically designed for exceptions via `<exception>`. `std::exception` contains a virtual member function called `what()` that returns a null-terminated character sequence (char *) and can be overwritten in derived classes.

**Generic exception types:**
- `logic_error` - for logic errors
- `runtime_error` - for runtime errors (e.g., `bad_alloc`)

**Example:**
```cpp
// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

int main () {
  try
  {
    int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}
// Here bad_alloc is caught
```

### Advantages of Exception Handling
- **Program continuity:** Errors are caught and handled without terminating the program; execution returns to the moment where it was caught
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
Create a `Bureaucrat` class that only exists when specific conditions are met. It has its own exceptions.

### Class Requirements

**Attributes:**
- Constant name (initialized in initializer list)
- Grade ranging from **1** (highest) to **150** (lowest)
  - *Note: Lower numbers = higher rank (like company hierarchy)*

**Mandatory Functions:**
- Canonical form: constructor, destructor, copy constructor, copy assignment operator
- Getters: `getName()` and `getGrade()`
- Grade manipulation: `incrementBureaucratGrade()` and `decrementBureaucratGrade()`
  - *Example: Incrementing grade 3 → grade 2*

**Exception Handling:**
Invalid grades must throw custom exceptions:
- `Bureaucrat::GradeTooHighException` (grade < 1)
- `Bureaucrat::GradeTooLowException` (grade > 150)

**Implementation:**
```cpp
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
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		// Getters
		const std::string&  getName() const;
		int                 getGrade() const;
		
		// Grade manipulation
		void incrementBureaucratGrade();
		void decrementBureaucratGrade();

		void signForm(Form& form);
		
	private:
		const std::string   _name;
		int                 _grade;
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
Create a `Form` class that requires appropriate bureaucrat grades for signing and execution. It has the same exceptions as Bureaucrat and they behave in the same way, but they belong to the Form class and should be used appropriately.

### Class Requirements

**Private Attributes** *(with corresponding getters)*:
- Constant name
- Boolean `_isSigned` (defaults to `false` at construction)
- Constant grade required to **sign** (signing only possible if bureaucrat's grade is high enough)
- Constant grade required to **execute** (execution only possible if bureaucrat's grade is high enough)

**Mandatory Functions:**
- Same canonical form as Bureaucrat class
- Same exception classes (but belonging to Form)
- Appropriate getters for all attributes

**Special Member Functions:**

The following member functions are specific to the Form class:
- `beSigned()` member function: Changes the form's `_isSigned` status if the grade is high enough (less than or equal to the required signing grade in the Form class). If too low, throw a `Form::GradeTooLowException`.

**Example:**
```cpp
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _SigningGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}
```

---

## ex02: Abstract Form Class and Concrete Forms

### Objective
In this exercise, the Form class must become an abstract class and is renamed `AForm`. The form's attributes remain private and belong to the base class.

We use inheritance for the forms, meaning all derived or child classes of the AForm class first construct a base class and then add features onto it.

### Three Derived Forms:

**ShrubberyCreationForm:**
- Required signing grade: 145
- Required executing grade: 137
- **Action:** Creates a file `<target>_shrubbery` in the working directory with an ASCII tree inside it
- *For this, we use the `<fstream>` class (creates and writes to a file)*

**RobotomyRequestForm:**
- Required signing grade: 72
- Required executing grade: 45
- **Action:** Makes drilling noises, then informs that `<target>` has been robotomized successfully in 50% of cases. Otherwise, it informs that the robotomy failed (two cases in if-else)

**PresidentialPardonForm:**
- Required signing grade: 25
- Required executing grade: 5
- **Action:** Informs that `<target>` has been pardoned by Zaphod Beeblebrox

**Constructor:** All of them take *only one parameter* in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.

### New Member Functions

**`execute(Bureaucrat const & executor) const`:**
- Needs to be added to the base AForm class
- Implements a function to execute the form's action in the concrete classes
- This is the pure virtual function (`= 0`) that makes AForm abstract

**Checks before execution:**
- Is the form signed? → yes / no
- Is the grade of the bureaucrat attempting to execute it high enough? → yes / no (remember grades are inverted)
- Otherwise, throw appropriate exception (add `FormNotSignedException`)

**`executeForm(AForm const & form) const`:**
- Needs to be added to Bureaucrat class
- Attempts to execute the form
- If successful, prints:
```cpp
std::cout << <bureaucrat> << " executed " << <form> << std::endl;
```

### Implementation

```cpp
class AForm
{
	public:
		// Constructors and destructors
		AForm();
		AForm(const std::string name, const int formSigningGrade, 
		      const int formExecutingGrade, const std::string &target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		// Getters
		const std::string&  getFormName() const;
		bool                getFormSignatureStatus() const;
		int                 getSigningGrade() const;
		int                 getExecutingGrade() const;
		const std::string&  getTarget() const;

		// Member functions
		virtual void        beSigned(const Bureaucrat& bureaucrat);
		virtual void        execute(Bureaucrat const & executor) const; // calls executeFormAction
		
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	protected:
		virtual void        executeFormAction(void) const = 0; // Pure virtual
		
	private:
		const std::string   _name;
		bool                _isSigned;
		const int           _SigningGrade;
		const int           _ExecutingGrade;
		const std::string   _target;
};
```

### Key Changes from ex01:

- **Abstract class:** Contains a pure virtual function (`executeFormAction() = 0`), which must be implemented in concrete classes
- **Virtual destructor:** Ensures the most derived version of the destructor is called for proper cleanup
- **Protected pure virtual:** `executeFormAction()` is protected and pure virtual, forcing derived classes to implement it
- **New exception:** `FormNotSignedException` for execution attempts on unsigned forms

---

## General Notes

**Remember:**
- Grades are inverted: 1 is highest, 150 is lowest
- Always check form signature status before execution
- Use try-catch blocks appropriately to handle exceptions
- Virtual destructors are essential when working with inheritance and polymorphism
- Pure virtual functions (`= 0`) make a class abstract
