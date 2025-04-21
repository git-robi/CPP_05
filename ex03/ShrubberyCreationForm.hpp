#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& other);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

        virtual void execute(Bureaucrat const& executor) const;
};

#endif