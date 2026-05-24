#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <sys/time.h> 

int main(int ac, char **av)
{
    try
    {
   
        if (ac < 2)
            throw PmergeMe::InvalidArg();
            
        PmergeMe obj;
        

        obj.parseInput(av);

        obj.printVec("Before: ");
        
        
        struct timeval start, end;

        gettimeofday(&start, NULL);
        
        obj.sortVec(); 
        
        gettimeofday(&end, NULL); 
        long timeVec = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
        

        gettimeofday(&start, NULL); 
        
        obj.sortDeq();
        
        gettimeofday(&end, NULL);
        
        long timeDeq = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
        

        obj.printVec("After:  ");
        
     
        std::cout << "Time to process a range of " << obj.getSize() 
                  << " elements with std::vector : " << timeVec << " us" << std::endl;
                  
        std::cout << "Time to process a range of " << obj.getSize() 
                  << " elements with std::deque  : " << timeDeq << " us" << std::endl;
                  
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}