



// 1. Split line
// 2. trim date
// 3. trim value
// 4. call isValidDate(date)
// 5. call isValidValue(value)

#include "BitcoinExchange.h" 



BitcoinExchange::BitcoinExchange()  {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    database = other.database;
}

BitcoinExchange &   BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
        database = other.database; 
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Check these things in order:
// 1. The string length must be 10
// 2. date[4] must be '-'
// 3. date[7] must be '-'
// 4. All other characters must be digits
// 5. Extract year, month, day
// 6. Month must be from 1 to 12
// 7. Day must be valid for that month
// 8. February 29 must only work in leap years

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if(date.length() != 10)
        return false;

    if(date[4] != '-' || date[7] != '-')
        return false;
    
    for(int i = 0; i < 10; i++)
    {
        if(i == 4  || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }

    int  month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());

    if(month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}

void    BitcoinExchange::loadDatabase(const std::string &filename)
{

}

void    BitcoinExchange::processInput(const std::string &filename) const
{

}
