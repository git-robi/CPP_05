#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm(target + "_Pardon", 25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other), target(other.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getSignStatus())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
