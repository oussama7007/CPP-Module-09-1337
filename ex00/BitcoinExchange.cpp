

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

const char *BitcoinExchange::EmptyDatabaseException::what()  const throw()
{
    return "Error: empty database";
}

const char *BitcoinExchange::fileOpenException::what() const throw()
{
    return "Error: could not open file.";
}


// Check these things in order:
// 1. The string length must be 10
// 2. date[4] must be '-'
// 3. date[7] must be '-'
// 4. All other characters must be digits
// 5. Extract year, month, day
// 6. Month must be from 1 to 12
// 7. Day must be valid for that month


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
        if(!std::isdigit(static_cast<unsigned char>(date[i])))
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
// 1. Start from the beginning of the string.
// 2. Move forward while the character is a space.
// 3. Start from the end of the string.
// 4. Move backward while the character is a space.
// 5. Return the middle part.

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t start = 0 ;
    size_t end = str.length();

    while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
        start++;

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        end--;

    return str.substr(start, end - start);

}



double BitcoinExchange::parseDouble(const std::string &str) const
{
    return std::strtod(str.c_str(), NULL);
}


bool BitcoinExchange::isValidValue(const std::string &value) const 
{
    char *end;

    if(value.empty())
        return false;

    std::strtod(value.c_str(), &end);

    if (*end != '\0')
        return false;

    return true;

}


void    BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw fileOpenException();
    
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos) //-1
            continue;
        std::string date = line.substr(0, comma);
        std::string priceStr = line.substr(comma + 1 );

        date = BitcoinExchange::trim(date);
        priceStr =  BitcoinExchange::trim(priceStr);

        if(!isValidDate(date))
            continue;
        if (!isValidValue(priceStr))
            continue;
        
        double price = parseDouble(priceStr);
        database[date]  = price;
    }
    if (database.empty())
        throw EmptyDatabaseException();

}



double BitcoinExchange::getRateForDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it;

    it = database.upper_bound(date);

    if (it == database.begin())
        throw std::runtime_error("Error: no earlier date in database.");

    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    if (database.empty())
        throw EmptyDatabaseException();

    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw fileOpenException();

    std::string line;

    if (!std::getline(file, line))
        return;

    if (trim(line) != "date | value")
        std::cout << "Error: bad header => " << line << std::endl;

    while (std::getline(file, line))
    {
        std::string cleanLine = trim(line);

        if (cleanLine.empty())
            continue;

        size_t pipe = line.find('|');

        if (pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << cleanLine << std::endl;
            continue;
        }

        if (line.find('|', pipe + 1) != std::string::npos)
        {
            std::cerr << "Error: bad input => " << cleanLine << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipe));
        std::string valueStr = trim(line.substr(pipe + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << cleanLine << std::endl;
            continue;
        }

        if (!isValidValue(valueStr))
        {
            std::cerr << "Error: bad input => " << cleanLine << std::endl;
            continue;
        }

        double value = parseDouble(valueStr);

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            double rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}