#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm(target + "_Robotomy", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other), target(other.target)
{}
 

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;

}
       
RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getSignStatus())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << "* drilling noises *" << std::endl;

    srand(time(NULL));
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}