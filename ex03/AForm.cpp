#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(std::string const formName, int sGrade, int eGrade)
    : name(formName), isSigned(false), signGrade(sGrade), execGrade(eGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw (GradeTooLowException());
    if (signGrade < 1 || execGrade < 1)
        throw (GradeTooHighException());
}

AForm::AForm(AForm const &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm(){}

std::string const AForm::getName() const
{
    return name;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

bool AForm::getSignStatus() const
{
    return isSigned;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName() << ":\n";
    os << "Status: " << (form.getSignStatus() ? "signed" : "not signed") << "\n";
    os << "Grade to sign: " << form.getSignGrade() << "\n";
    os << "Grade to execute: " << form.getExecGrade();
    return os;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= getSignGrade())
        isSigned = true;
    else
        throw(GradeTooLowException());
}