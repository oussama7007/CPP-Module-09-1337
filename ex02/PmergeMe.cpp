


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




