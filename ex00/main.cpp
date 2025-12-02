#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Bureaucrat.hpp"

static void printTestHeader(const std::string& testName, int testNum)
{
    std::cout << "\n" << BOLD << CYAN << "═══════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "TEST " << testNum << ": " << testName << RESET << std::endl;
    std::cout << BOLD << CYAN << "═══════════════════════════════════════" << RESET << std::endl;
}

static void printSuccess(const std::string& message = "Test passed")
{
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
}

static void printFailure(const std::string& message = "Test failed")
{
    std::cout << RED << "✗ " << message << RESET << std::endl;
}

static void printAction(const std::string& action)
{
    std::cout << BLUE << "→ " << action << RESET << std::endl;
}

static void constructorOfRangeGradesTest()
{
    printTestHeader("Constructor with Out-of-Range Grades", 1);
    
    // Test grade too low (> 150)
    printAction("Attempting to create bureaucrat with grade 160 (too low)...");
    try
    {
        Bureaucrat test("Bob", 160);
        std::cout << test << std::endl;
        printFailure("Should have thrown exception!");
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
        printSuccess();
    }
    
    std::cout << std::endl;
    
    // Test grade too high (< 1)
    printAction("Attempting to create bureaucrat with grade 0 (too high)...");
    try
    {
        Bureaucrat test2("Alice", 0);
        std::cout << test2 << std::endl;
        printFailure("Should have thrown exception!");
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
        printSuccess();
    }
}

static void incrementOutofRangeTest()
{
    printTestHeader("Increment Grade Out of Range", 2);
    
    try
    {
        printAction("Creating Bob with grade 1 (highest possible)...");
        Bureaucrat test("Bob", 1);
        std::cout << test << std::endl;
        
        printAction("Attempting to increment grade beyond 1...");
        test.incrementBureaucratGrade();
        printFailure("Should have thrown exception!");
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
        printSuccess();
    }
}

static void decrementOutofRangeTest()
{
    printTestHeader("Decrement Grade Within Range", 3);
    
    try
    {
        printAction("Creating Bob with grade 1...");
        Bureaucrat test("Bob", 1);
        std::cout << test << std::endl;
        
        printAction("Decrementing grade to 2 (valid operation)...");
        test.decrementBureaucratGrade();
        std::cout << test << std::endl;
        printSuccess();
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
        printFailure("Should not have thrown exception!");
    }
}

static void correctValuesTest()
{
    printTestHeader("Operations with Valid Grades", 4);
    
    try
    {
        printAction("Creating Charlie with grade 50...");
        Bureaucrat test("Charlie", 50);
        std::cout << test << std::endl;
        
        printAction("Incrementing grade (50 → 49)...");
        test.incrementBureaucratGrade();
        std::cout << test << std::endl;
        
        printAction("Decrementing grade (49 → 50)...");
        test.decrementBureaucratGrade();
        std::cout << test << std::endl;
        
        printSuccess("All operations completed successfully");
    }
    catch(const std::exception& e)
    {
        std::cerr << MAGENTA << "Exception caught: " << e.what() << RESET << std::endl;
        printFailure();
    }
}

int main()
{
    std::cout << BOLD << CYAN << "BUREAUCRAT CLASS TEST" << RESET << std::endl;
    
    constructorOfRangeGradesTest();
    incrementOutofRangeTest();
    decrementOutofRangeTest();
    correctValuesTest();
    
    std::cout << std::endl;
    
    return 0;
}
