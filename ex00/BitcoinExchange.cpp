















#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>


class   BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        // void loadDatabase(const std::string &filename);
        // void processInput(const std::string &filename) const;







    }



#endif















// class BitcoinExchange
// {
// private:
//     std::map<std::string, double> _database;

// public:
//     BitcoinExchange();
//     BitcoinExchange(const BitcoinExchange &other);
//     BitcoinExchange &operator=(const BitcoinExchange &other);
//     ~BitcoinExchange();

//     void loadDatabase(const std::string &filename);
//     void processInput(const std::string &filename) const;

// private:
//     bool isValidDate(const std::string &date) const;
//     bool isValidValue(const std::string &value) const;
//     double parseDouble(const std::string &str) const;
//     double getRateForDate(const std::string &date) const;
//     std::string trim(const std::string &str) const;
// };

