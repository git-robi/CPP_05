#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), execGrade(150)
{
}

Form::Form(std::string const formName, int sGrade, int eGrade)
    : name(formName), isSigned(false), signGrade(sGrade), execGrade(eGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw (GradeTooLowException());
    if (signGrade < 1 || execGrade < 1)
        throw (GradeTooHighException());
}

Form::Form(Form const &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form(){}

std::string const Form::getName() const
{
    return name;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

bool Form::getSignStatus() const
{
    return isSigned;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form " << form.getName() << ":\n";
    os << "Status: " << (form.getSignStatus() ? "signed" : "not signed") << "\n";
    os << "Grade to sign: " << form.getSignGrade() << "\n";
    os << "Grade to execute: " << form.getExecGrade();
    return os;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= getSignGrade())
        isSigned = true;
    else
        throw(GradeTooLowException());
}