#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};

#endif