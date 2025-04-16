#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat Bureaucrat::operator<<(Bureaucrat &other)
{
    std::cout << name << ", bureaucrat grade" << grade << std::endl;
}

Bureaucrat::Bureaucrat() : name(name), grade(grade)
{
    if (grade < 1)
        GradeTooHighException();
    else if (grade > 150)
        GradeTooLowException();

}
std::string const Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade(Bureaucrat Bureaucrat)
{
    if (grade - 1 < 1)
    GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementGrade(Bureaucrat Bureaucrat)
{
    if (grade + 1 > 150)
    GradeTooLowException();
    else
        grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
    return "Grade is too low";
}