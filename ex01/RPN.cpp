




#include "RPN.h"






RPN::RPN()
{
}

RPN::RPN(const RPN& other) : stack(other.stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->stack = other.stack;
    return *this;
}

RPN::~RPN()
{
}

const char* RPN::Error::what() const throw()
{
    return "Error";
}