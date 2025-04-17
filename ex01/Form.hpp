#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const signGrade;
        int const execGrade;

    public:

        Form();
        Form(std::string const name, int signGrade, int execGrade);
        Form(const Form &other);
        Form& operator=(const Form& other);
        ~Form();

        std::string const getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSignStatus() const;

        void beSigned(Bureaucrat bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif