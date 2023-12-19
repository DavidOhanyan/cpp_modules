/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:49:51 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/19 14:48:40 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ){}
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& ){return (*this);}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::splitString(const std::string& input, char delimiter)
{
	std::stringstream ss(input);
	std::string token;

	while (std::getline(ss, token, delimiter)) 
		BitcoinExchange::dq.push_back(token);
}

void BitcoinExchange::removeSpaces(std::string &str) 
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

bool BitcoinExchange::is_all_num(const std::string& str) 
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
        	if (c == '.' && !dotFound && str[i + 1] != '\0')
            	dotFound = true;
        	else 
            	return false;
    	}
	}
	return (true);
}

bool BitcoinExchange::isLeapYear( int year ) 
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::validateDbValue()
{
	double res;
	if (!BitcoinExchange::is_all_num(value))
		return (false);
	res = std::strtod(value.c_str(), NULL);
	if (res < 0 || res > 100000)
		return (false);
	return (true);
}

bool BitcoinExchange::validateKey()
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

int BitcoinExchange::validateInValue()
{
	if (!BitcoinExchange::is_all_num(BitcoinExchange::value))
		return (1);
	if (BitcoinExchange::value.size() > 4 || std::atol(BitcoinExchange::value.c_str()) > 1000)
		return (2);
	if (BitcoinExchange::value.size() > 4 || std::atol(BitcoinExchange::value.c_str()) < 0)
		return (3);
	return (0);
}

void BitcoinExchange::dbFile(std::string fname)
{
	std::ifstream file(fname.c_str());
	std::string line;
	size_t comma;
	if (!file.is_open())
        throw std::runtime_error(ERR_UNAVAILABLE_DB);
	
	if (std::getline(file, line) && line != "date,exchange_rate")
		  throw std::runtime_error(ERR_EMPTY_DB);
	while (!file.eof())
	{
		std::getline(file, line);
		if ((comma = line.find(',')) == std::string::npos)
			throw std::runtime_error(ERR_INVALID_DB);
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
			throw std::runtime_error(ERR_INVALID_DB);
		}
	}
	if (BitcoinExchange::map.empty())
		throw std::runtime_error(ERR_EMPTY_DB);
}

void BitcoinExchange::infile(std::string fname)
{
	std::ifstream file(fname.c_str());
	std::string line;
	std::string rem;
	size_t pipe;
	int i = 0;
	if (!file.is_open())
        throw std::runtime_error(ERR_INVALID_INPUT_FILE);
	std::getline(file, line);
	if ( line != "date | value" || file.eof())
		 throw std::runtime_error(ERR_INVALID_IN);
	while (!file.eof())
	{
		std::getline(file, line);
		rem = line;
		BitcoinExchange::removeSpaces(line);
		if ((pipe = line.find('|')) == std::string::npos)
		{
	 		std::cout << ERR_BAD_INPUT << rem <<std::endl;
			continue;
		}
		BitcoinExchange::key = line.substr(0, pipe);
		BitcoinExchange::value = line.substr(pipe + 1, line.size());
		BitcoinExchange::splitString(BitcoinExchange::key, '-');
		if (!BitcoinExchange::validateKey())
		{
			std::cout << ERR_BAD_INPUT << rem << std::endl;
			BitcoinExchange::dq.clear();
			continue;
		}
		i = BitcoinExchange::validateInValue();
		switch (i)
		{
			case 1: std::cout << ERR_BAD_INPUT << rem << std::endl;
			{
				BitcoinExchange::dq.clear();
				break;
			}
			case 2: std::cout << ERR_LARGE_NUM << std::endl;
			{
				BitcoinExchange::dq.clear();
				break;
			}
			case 3: std::cout << ERR_NEG_NUM << std::endl;
			{
				BitcoinExchange::dq.clear();
				break;
			}
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
				BitcoinExchange::dq.clear();
			}
		}
	 }
	BitcoinExchange::map.clear();
	BitcoinExchange::dq.clear();
}

std::map<std::string, double> BitcoinExchange::map;
std::deque<std::string> BitcoinExchange::dq;
std::string BitcoinExchange::key;
std::string BitcoinExchange::value;