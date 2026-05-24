




#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <exception>

class RPN
{
    private :
        std::stack<int> stack;
        
        bool isOperator(const std::string& token) const;
        int applyOperation(int lhs, int rhs, char op) const;
     
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