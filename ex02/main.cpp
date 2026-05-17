




#include "PmergeMe.h"



int main(int ac, char **av)
{
    if(ac < 2)
        throw PmergeMe::InvalidArg();
    try
    {
        PmergeMe obj;
        obj.parseInput(av);

        obj.printVec("Before: ");
        std::cout << "Total elements parsed: " << obj.getSize() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout <<  e.what() << std::endl;
    }
    
}