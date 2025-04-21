#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("Shrubbery_" + target, 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm(other), target(other.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!getSignStatus())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outFile((target + "_shrubbery").c_str());
    
    if (!outFile.is_open())
            throw std::runtime_error("Cannot create file");
    
        // Write ASCII tree
        outFile << "       ###\n";
        outFile << "      #o###\n";
        outFile << "    #####o###\n";
        outFile << "   #o#\\#|#/###\n";
        outFile << "    ###\\|/#o#\n";
        outFile << "       }|{  \n";
        outFile << "       }|{\n";
    
        outFile.close();
    
}