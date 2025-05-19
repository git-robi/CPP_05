#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string Intern::formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

const Intern::FormCreator Intern::formCreators[3] = {
    &Intern::createShrubberyForm,
    &Intern::createRobotomyForm,
    &Intern::createPresidentialForm
};

Intern::Intern(){}

Intern::Intern(Intern &other)
{
    *this = other;
}

Intern& Intern::operator=(Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(formTarget);
        }
    }
    std::cout << "Form " << formName << " does not exist." << std::endl;
    return NULL;
}
