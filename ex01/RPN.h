




#ifndef RPN_H
#define RPN_H


#include <iostream>
#include <stack>
#include <exception>

class RPN
{
    private :
        std::stack<int> stack;
        

    public:
        RPN();
        RPN(const RPN& other);
        RPN & operator=(const RPN& other);
        ~RPN();
        class Error : public std::exception 
        {
            public:
                const char *what() const throw() ;
        };
        int     calculate(const std::string &expression);

};



#endif