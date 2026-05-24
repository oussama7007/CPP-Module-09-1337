


#ifndef PmergeMe_HPP
#define PmergeMe_HPP

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
        size_t getJacobsthalNumber(size_t n);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        class InvalidInput : public  std::exception
        {
            public:
                const char *what() const throw();
        };
        class   OutofRange : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class InvalidArg : public std::exception 
        {
            public:
                const char *what() const throw();
        };
        
        void    parseInput(char **av);
        void    sortVec();
        void    sortDeq();
        size_t getSize() const;
        void    printVec(const std::string& message) const;
};



#endif