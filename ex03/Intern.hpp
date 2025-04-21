#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(Intern &other);
        Intern& operator=(Intern &other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string formTarget);
};

#endif