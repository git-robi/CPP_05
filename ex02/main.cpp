#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        // Test 1: High-level bureaucrat with all forms
        std::cout << "=== Test 1: High-level bureaucrat with all forms ===\n";
        Bureaucrat president("President", 1);
        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        shrubbery.beSigned(president);
        robotomy.beSigned(president);
        pardon.beSigned(president);

        shrubbery.execute(president);
        robotomy.execute(president);
        pardon.execute(president);

        // Test 2: Mid-level bureaucrat (grade 70)
        std::cout << "\n=== Test 2: Mid-level bureaucrat ===\n";
        Bureaucrat manager("Manager", 70);  // Can only sign/execute Shrubbery
        ShrubberyCreationForm tree("park");
        RobotomyRequestForm robot("C3PO");

        tree.beSigned(manager);
        tree.execute(manager);

        try {
            robot.beSigned(manager);  // Should fail
        } catch (std::exception& e) {
            std::cout << "Error (expected): " << e.what() << std::endl;
        }

        // Test 3: Multiple robotomy attempts
        std::cout << "\n=== Test 3: Multiple robotomy attempts ===\n";
        RobotomyRequestForm robot1("R2D2");
        robot1.beSigned(president);
        for (int i = 0; i < 4; i++) {
            std::cout << "Attempt " << i + 1 << ": ";
            robot1.execute(president);
        }

        // Test 4: Execute without signing
        std::cout << "\n=== Test 4: Execute without signing ===\n";
        PresidentialPardonForm unsignedPardon("Arthur Dent");
        try {
            unsignedPardon.execute(president);
        } catch (std::exception& e) {
            std::cout << "Error (expected): " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}