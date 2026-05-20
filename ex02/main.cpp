#include "PmergeMe.h"
#include <iostream>
#include <exception>
#include <sys/time.h> // Required for gettimeofday

int main(int ac, char **av)
{
    try
    {
        // 1. Check arguments
        if (ac < 2)
            throw PmergeMe::InvalidArg();
            
        PmergeMe obj;
        
        // 2. Parse the input
        obj.parseInput(av);
        
        // 3. Print the array before sorting
        obj.printVec("Before: ");
        
        // Structure to hold the time values
        struct timeval start, end;
        
        // ==========================================
        // Measure time for std::vector
        // ==========================================
        gettimeofday(&start, NULL); // Record start time
        
        obj.sortVec(); // Sort the vector
        
        gettimeofday(&end, NULL); // Record end time
        
        // Calculate the difference in microseconds
        long timeVec = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
        
        // ==========================================
        // Measure time for std::deque
        // ==========================================
        gettimeofday(&start, NULL); // Record start time
        
        obj.sortDeq(); // Sort the deque
        
        gettimeofday(&end, NULL); // Record end time
        
        // Calculate the difference in microseconds
        long timeDeq = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
        
        // ==========================================
        // Final Output
        // ==========================================
        
        // 4. Print the array after sorting
        obj.printVec("After:  ");
        
        // 5. Print the time taken for each container
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