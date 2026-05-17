


#include "PmergeMe.h"


PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec) , deq(other.deq)
{
}

PmergeMe & PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(char **av)
{
    for (int i = 1; av[i]; ++i)
    {
        std::string arg(av[i]);
        
        
        if (arg.empty() || arg.find_first_not_of(" \t") == std::string::npos)
            throw std::invalid_argument("Error: Empty or whitespace-only argument.");

        std::istringstream iss(arg);
        std::string token;

        while (iss >> token)
        {

            if (token.find_first_not_of("0123456789+") != std::string::npos)
                throw std::invalid_argument("Error: Invalid character in sequence.");
                

            if (token.find('+') != std::string::npos && (token.find('+') != 0 || token.length() == 1))
                throw std::invalid_argument("Error: Invalid formatting.");

            long val = std::atol(token.c_str());
            
            if (val < 0 || val > 2147483647)
                throw std::invalid_argument("Error: Number out of range.");

            int intVal = static_cast<int>(val);

           
            if (std::find(vec.begin(), vec.end(), intVal) != vec.end())
                throw std::invalid_argument("Error: Duplicate numbers are not allowed.");

            
            vec.push_back(intVal);
            deq.push_back(intVal);
        }
    }
}


void PmergeMe::printVec(const std::string& message) const
{
    std::cout << message; 
    
    
    size_t limit = vec.size() > 5 ? 5 : vec.size();

    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << vec[i] << " ";
    }
    
    if (vec.size() > 5)
        std::cout << "[...]"; 

    std::cout << std::endl;
}

