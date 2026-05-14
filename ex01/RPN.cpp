#include "RPN.h"
#include <sstream>

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

void RPN::clearStack()
{
    while (!stack.empty())
        stack.pop();
}

bool RPN::isOperator(const std::string& token) const
{
    return token.length() == 1 &&
        (token[0] == '+' || token[0] == '-' ||
         token[0] == '*' || token[0] == '/');
}

int RPN::applyOperation(int left, int right, char op) const
{
    if (op == '+')
        return left + right;
    if (op == '-')
        return left - right;
    if (op == '*')
        return left * right;
    if (op == '/')
    {
        if (right == 0)
            throw Error();
        return left / right;
    }
    throw Error();
}

int RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    clearStack();

    while (iss >> token) // extraction operator
    {
        if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        {
            stack.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (stack.size() < 2)
                throw Error();

            int right = stack.top();
            stack.pop();

            int left = stack.top();
            stack.pop();

            stack.push(applyOperation(left, right, token[0]));
        }
        else
        {
            throw Error();
        }
    }

    if (stack.size() != 1)
        throw Error();

    int result = stack.top();
    clearStack();

    return result;
}