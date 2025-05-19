#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(std::string target);
        AForm* createShrubberyForm(std::string target);
        AForm* createRobotomyForm(std::string target);
        AForm* createPresidentialForm(std::string target);
        
        static const std::string formNames[3];
        static const FormCreator formCreators[3];

    public:
        Intern();
        Intern(Intern &other);
        Intern& operator=(Intern &other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string formTarget);
};

#endif