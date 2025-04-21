#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(Intern &other)
{
    *this = other;
}

Intern& Intern::operator=(Intern &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm *Form = NULL;
    int i = 0;
    while (i < 3 && formNames[i] != formName)
        i++;
    switch (i)
    {
        case 0:
        {
            Form = new ShrubberyCreationForm(formTarget);
                break;
        }
        case 1:
        {
            Form = new RobotomyRequestForm(formTarget);
                break;
        }
        case 2:
        {
            Form = new PresidentialPardonForm(formTarget);
                break;
        }
        default:
        {
            std::cout << "Form " << formName << " does not exist." << std::endl;
            break;
        }
    }
    if (Form != NULL)
        std::cout << "Intern creates " << formName << std::endl;
    return Form;

}


