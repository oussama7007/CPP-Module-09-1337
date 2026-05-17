




#include "PmergeMe.h"



int main(int ac, char **av)
{
    if(ac < 2)
        throw PmergeMe::InvalidArg();
    try
    {
        PmergeMe obj
    }
    catch(const std::exception &e)
    {
        std::cout <<  e.what() << std::endl;
    }
    
}