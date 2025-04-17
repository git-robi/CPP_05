#include "Bureaucrat.hpp"

int main()
{
    //valid range grade
    try 
    {
        Bureaucrat BureaucratOne("one", 50);
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    //try with grade too low
    std::cout << "Try grade too low: " << std::endl; 
    try 
    {
        Bureaucrat BureaucratTwo("two", 151);
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;;
    }

    std::cout << std::endl;

    //try with grade too high
    std::cout << "Try grade too high: " << std::endl;
    try 
    {
        Bureaucrat BureaucratThree("three", 0);
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;;
    }
    std::cout << std::endl;
    
    //try decrements and increments 
    Bureaucrat BureaucratFour("four", 149);

    std::cout << "Before decrement: " << std::endl; 
    std::cout << BureaucratFour << std::endl;
    std::cout << std::endl;

    //decrement in range
    try 
    {
        BureaucratFour.decrementGrade();
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "After decrement in range: " << std::endl; 
    std::cout << BureaucratFour << std::endl;
    std::cout << std::endl;
    
    
    //try to decrement grade out of bound
    std::cout << "Try decrement out of bounds: " << std::endl; 
    try 
    {
        BureaucratFour.decrementGrade();
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    //try to increment grade out of bound

    Bureaucrat BureaucratFive("five", 2);

    std::cout << "Before increment: " << std::endl; 
    std::cout << BureaucratFive << std::endl;
    std::cout << std::endl;

    //increment in range
    try 
    {
        BureaucratFive.incrementGrade();
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "After increment in range: " << std::endl; 
    std::cout << BureaucratFive << std::endl;
    std::cout << std::endl;
    
    
    //try to increment grade out of bound
    std::cout << "Try increment out of bounds: " << std::endl; 
    try 
    {
        BureaucratFive.incrementGrade();
    }
    catch (std:: exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}