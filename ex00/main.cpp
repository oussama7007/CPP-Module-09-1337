#include <iostream>
#include <exception>
#include <stdexcept>

class BadException : public std::exception
{
public:
     const char *what() const throw()
    {
        std::cout << "Inside what(), now I will throw another exception..." << std::endl;

        // throw std::runtime_error("Error thrown from what()");

        return "This will never be returned";
    }
};

int main()
{
    try
    {
        throw BadException();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught BadException" << std::endl;

        std::cout << e.what() << std::endl;

        std::cout << "This line will probably not be printed" << std::endl;
    }

    std::cout << "End of program" << std::endl;

    return 0;
}