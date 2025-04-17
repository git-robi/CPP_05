#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Testing Form Creation ===" << std::endl;
    
    // Test 1: Valid Form creation
    try {
        Form validForm("Tax Form", 100, 50);
        std::cout << validForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Form with too high grade
    std::cout << "Testing form with too high grade (0):" << std::endl;
    try {
        Form highForm("High Form", 0, 50);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Form with too low grade
    std::cout << "Testing form with too low grade (151):" << std::endl;
    try {
        Form lowForm("Low Form", 151, 50);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Testing form signing
    std::cout << "=== Testing Form Signing ===" << std::endl;
    Form testForm("Test Form", 100, 50);
    Bureaucrat highBureaucrat("Boss", 1);
    Bureaucrat lowBureaucrat("Intern", 150);

    std::cout << "Initial form state:" << std::endl;
    std::cout << testForm << std::endl << std::endl;

    // Try signing with low-level bureaucrat
    std::cout << "Trying to sign with low-level bureaucrat:" << std::endl;
    try {
        testForm.beSigned(lowBureaucrat);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << testForm << std::endl << std::endl;

    // Try signing with high-level bureaucrat
    std::cout << "Trying to sign with high-level bureaucrat:" << std::endl;
    try {
        testForm.beSigned(highBureaucrat);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << testForm << std::endl;

    return 0;
}