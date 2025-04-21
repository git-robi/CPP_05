#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat one("bob", 1);
    ShrubberyCreationForm form("tree");

    form.beSigned(one);
    form.execute(one);

}