


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

    
#include <iostream>


#include <map>
  
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>


class   BitcoinExchange
{
    private:

        std::map<std::string, double> database;
        
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;
        double parseDouble(const std::string &str) const;
        double getRateForDate(const std::string &date) const;
        std::string trim(const std::string &str) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        class fileOpenException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        class EmptyDatabaseException : public std::exception  
        {
            public:
                const char *what() const throw();
        };
        void loadDatabase(const std::string &filename);
        void processInput(const std::string &filename) const;

};

#endif

