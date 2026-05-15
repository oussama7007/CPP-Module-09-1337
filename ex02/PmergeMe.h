


#ifndef PmergeMe_H
#define PmergeMe_H


#include <iostream>
#include <vector>
#include <exception>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parseInput(char **av);
        void    sortVec();
        void    sortDeq();
        
};



#endif