#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
int main()
{
    Intern someRandomIntern;
    Bureaucrat one("One", 4);

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");

    if (rrf)
    {
        one.signForm(*rrf);
        one.executeForm(*rrf);
    }

    if (scf)
    {
        one.signForm(*scf);
        one.executeForm(*scf);
    }

    if (ppf)
    {
        one.signForm(*ppf);
        one.executeForm(*ppf);
    }

    delete rrf;
    delete scf;
    delete ppf;

    return 0;
}