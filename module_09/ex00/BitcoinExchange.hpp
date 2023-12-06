/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:21 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/06 21:43:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <cstdlib>


class BitcoinExchange
{
private:
	static std::deque<std::string> dq;
	static std::map<std::string, double> map;
	static std::string key;
	static std::string value;
private:
	BitcoinExchange(){}
	BitcoinExchange(const BitcoinExchange& ){}
	BitcoinExchange& operator= (const BitcoinExchange& ){return (*this);}
	~BitcoinExchange(){}
private:
	static void splitString(const std::string& input, char delimiter)
	{
    	std::stringstream ss(input);
    	std::string token;
    
    	while (std::getline(ss, token, delimiter)) 
			BitcoinExchange::dq.push_back(token);
	}
	static void removeSpaces(std::string &str) 
	{
    	std::string::iterator iter = str.begin();
    	while (iter != str.end()) 
		{
        if (std::isspace(*iter)) 
            iter = str.erase(iter);
		else
            ++iter;
		}
	}
	static bool is_all_num(const std::string& str) 
	{
    	bool dotFound = false;
		size_t i = 0;
		if (str[i] == '-')
			i++;
    	for (; i < str.length(); ++i) 
		{
        	char c = str[i];
        	if (!isdigit(c)) 
			{
            	if (c == '.' && !dotFound)
                	dotFound = true;
            	else 
                	return false;
        	}
   		}
		return (true);
	}
	static bool isLeapYear( int year ) 
	{
    	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	static bool validateDbValue()
	{
		double res;
		if (!BitcoinExchange::is_all_num(value))
			return (false);
		res = std::strtod(value.c_str(), NULL);
		if (res < 0 || res > 100000)
			return (false);
		return (true);
	}
	static bool validateKey()
	{
		if (BitcoinExchange::dq.size() != 3)
			return (false);
		if (!BitcoinExchange::is_all_num(BitcoinExchange::dq[0]) || 
			!BitcoinExchange::is_all_num(BitcoinExchange::dq[1]) || 
			!BitcoinExchange::is_all_num(BitcoinExchange::dq[2]))
			return (false);
		int Manth_Day[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int Year = std::atoi(BitcoinExchange::dq[0].c_str());
		int Manth = std::atoi(BitcoinExchange::dq[1].c_str());
		int Day = std::atoi(BitcoinExchange::dq[2].c_str());
		
		if (Year < 2009 || Year > 2024)
			return (false);
		if (Manth < 1 || Manth > 12)
			return (false);
		if (Day < 1 || Day > 31)
			return (false);
		if (Manth == 2 && BitcoinExchange::isLeapYear(Year))
			Manth_Day[2] = 29;
		if (Manth_Day[Manth] < Day)
		  	return (false);
		return (true);
	}
	static int validateInValue()
	{
		if (!BitcoinExchange::is_all_num(BitcoinExchange::value))
			return (1);
		if (BitcoinExchange::value.size() > 4 || std::atol(BitcoinExchange::value.c_str()) > 1000)
			return (2);
		if (BitcoinExchange::value.size() > 4 || std::atol(BitcoinExchange::value.c_str()) < 0)
			return (3);
		return (0);
	}
public:
	static void dbFile(std::string fname)
	{
		std::ifstream file(fname.c_str());
		std::string line;
		size_t comma;
    	if (!file.is_open())
            throw std::runtime_error("Unable to open file\n");
		
		if (std::getline(file, line) && line != "date,exchange_rate")
			  throw std::runtime_error("lol\n");
		while (!file.eof())
		{
			std::getline(file, line);
			if ((comma = line.find(',')) == std::string::npos)
				throw std::runtime_error("storaket\n");
			BitcoinExchange::key = line.substr(0, comma);
			BitcoinExchange::value = line.substr(comma + 1, line.size());
			BitcoinExchange::splitString(BitcoinExchange::key, '-');
			if (BitcoinExchange::validateKey() && BitcoinExchange::validateDbValue())
			{
				BitcoinExchange::map[BitcoinExchange::key] = std::strtod(BitcoinExchange::value.c_str(), NULL);
				BitcoinExchange::dq.clear();
			}
			else
			{
				BitcoinExchange::dq.clear();
				BitcoinExchange::map.clear();
				throw std::runtime_error("vat tiv\n");
			}
		}
		if (BitcoinExchange::map.empty())
			throw std::runtime_error("datark\n");
	}

	static void infile(std::string fname)
	{
		std::ifstream file(fname.c_str());
		std::string line;
		std::string rem;
		size_t pipe;
		int i = 0;
    	if (!file.is_open())
            throw std::runtime_error("Unable to open file\n");
		std::getline(file, line);
		if ( line != "date | value" || file.eof())
			 throw std::runtime_error("Wrong in name\n");
		while (!file.eof())
		{
			std::getline(file, line);
			rem = line;
			BitcoinExchange::removeSpaces(line);
			if ((pipe = line.find('|')) == std::string::npos)
			{
		 		std::cout <<"Error: bad input => " << rem <<std::endl;
				continue;
			}
			BitcoinExchange::key = line.substr(0, pipe);
			BitcoinExchange::value = line.substr(pipe + 1, line.size());
			BitcoinExchange::splitString(BitcoinExchange::key, '-');
			if (!BitcoinExchange::validateKey())
			{
				std::cout <<"Error: bad input => " << rem << std::endl;
				continue;
			}
			i = BitcoinExchange::validateInValue();
			BitcoinExchange::dq.clear();
			switch (i)
			{
				case 1: std::cout << "Error: bad input => " << rem << std::endl;
					break;
				case 2: std::cout << "Error: too large a number." << std::endl;
					break;
				case 3: std::cout << "Error: not a positive number." << std::endl;
					break;
				default:
				{
					std::map<std::string, double>::iterator target;
					std::map<std::string, double>::iterator start = BitcoinExchange::map.begin();
    				std::map<std::string, double>::iterator bound = BitcoinExchange::map.upper_bound(BitcoinExchange::key);
				
    				target = bound;
    				if (bound != start)
    				    target = --bound;
   	 				const double result = std::strtod(BitcoinExchange::value.c_str(), NULL) * target->second;
					std::cout << BitcoinExchange::key << " => " << BitcoinExchange::value << " = " << result << std::endl;
				}
			}
		 }
		BitcoinExchange::map.clear();
	}
};


std::map<std::string, double> BitcoinExchange::map;
std::deque<std::string> BitcoinExchange::dq;
std::string BitcoinExchange::key;
std::string BitcoinExchange::value;

#endif