#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const signGrade;
        int const execGrade;

    public:

        AForm();
        AForm(std::string const name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string const getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSignStatus() const;

        void beSigned(Bureaucrat bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif