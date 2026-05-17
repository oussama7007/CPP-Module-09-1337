


#ifndef PmergeMe_H
#define PmergeMe_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>
#include <deque>
#include <sstream>
class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        
        void fordJohnsonVector(std::vector<int>& arr);
        void fordJohnsonDeque(std::deque<int>& arr);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parseInput(char **av);
        void    sortVec();
        void    sortDeq();

        void    printVec(const std::string& message) const;
};



#endif