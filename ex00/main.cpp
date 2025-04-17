#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Testing Bureaucrat Creation ===" << std::endl;
    
    // Test 1: Valid Bureaucrat creation
    std::cout << "Creating valid Bureaucrat (grade 1):" << std::endl;
    try 
    {
        Bureaucrat bureaucratOne("one", 1);
        std::cout << bureaucratOne << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Grade too low
    std::cout << "Testing grade too low (151):" << std::endl;
    try 
    {
        Bureaucrat bureaucratTwo("two", 151);
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Grade too high
    std::cout << "Testing grade too high (0):" << std::endl;
    try 
    {
        Bureaucrat bureaucratThree("three", 0);
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Testing Grade Modifications ===" << std::endl;
    
    // Test 4: Decrement tests
    std::cout << "--- Testing Decrement ---" << std::endl;
    Bureaucrat bureaucratFour("four", 149);

    std::cout << "Initial state:" << std::endl;
    std::cout << bureaucratFour << std::endl << std::endl;

    // Decrement in range
    std::cout << "Decrementing grade (149 -> 150):" << std::endl;
    try 
    {
        bureaucratFour.decrementGrade();
        std::cout << bureaucratFour << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    // Try to decrement out of bounds
    std::cout << "Attempting to decrement beyond minimum (150 -> 151):" << std::endl;
    try 
    {
        bureaucratFour.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Increment tests
    std::cout << "--- Testing Increment ---" << std::endl;
    Bureaucrat bureaucratFive("five", 2);

    std::cout << "Initial state:" << std::endl;
    std::cout << bureaucratFive << std::endl << std::endl;

    // Increment in range
    std::cout << "Incrementing grade (2 -> 1):" << std::endl;
    try 
    {
        bureaucratFive.incrementGrade();
        std::cout << bureaucratFive << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    // Try to increment out of bounds
    std::cout << "Attempting to increment beyond maximum (1 -> 0):" << std::endl;
    try 
    {
        bureaucratFive.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}