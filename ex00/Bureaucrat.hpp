#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat operator<<(Bureaucrat& other);

    std::string const getName() const;
    int getGrade() const;
    void incrementGrade(Bureaucrat Bureaucrat);
    void decrementGrade(Bureaucrat Bureaucrat);
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

#endif