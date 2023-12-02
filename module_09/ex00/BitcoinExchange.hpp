/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:21 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/02 21:37:33 by dohanyan         ###   ########.fr       */
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
	static std::vector<std::string> vec;
	static std::vector<std::string> splited;
	static std::map<std::string, double> map;
	static std::string key;
	static std::string value;
	static std::string result[3];
private:
	BitcoinExchange(){}
	BitcoinExchange(const BitcoinExchange& ){}
	BitcoinExchange& operator= (const BitcoinExchange& ){return (*this);}
	~BitcoinExchange(){}
public:
	static int countOccurrences(const std::string& str, char target)
	{
    	int count = 0;
    	for (size_t i = 0; i < str.length(); ++i) 
		{
        	if (str[i] == target)
            	count++;
    	}
    	return (count);
	}
	static void splitString(const std::string& input, char delimiter)
	{
    	std::stringstream ss(input);
    	std::string token;
		int i = 0;
    
    	while (std::getline(ss, token, delimiter)) 
			result[i++] = token;
	}
	static void removeSpaceTab(std::string& str)
	{
    	for (size_t i = 0; i < str.length(); ++i)
		{
        	if (std::isspace(str[i])) 
			{
            	str.erase(i, 1);
            	--i;
        	}
    	}
	}
	// static bool onlyOne(std::string line, char ch)
	// {
	// 	size_t first = line.find(ch);
	// 	if (first != std::string::npos)
	// 	{
	// 		size_t second = line.find(ch, first + 1);
	// 		if (second == std::string::npos)
	// 			return (true);
	// 	}
	// 	return (false);
	// }
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
	static void validateValue()
	{
		double res;
		if (!BitcoinExchange::is_all_num(value))
			throw std::runtime_error("vata\n");
		res = std::strtod(value.c_str(), NULL);
		if (res < 0 || res > 100000)
			throw std::runtime_error("big size\n");
		BitcoinExchange::map[key] = res;
	}
	static bool validateKey()
	{
		if (!BitcoinExchange::is_all_num(BitcoinExchange::result[0]) || 
			!BitcoinExchange::is_all_num(BitcoinExchange::result[1]) || 
			!BitcoinExchange::is_all_num(BitcoinExchange::result[2]))
			return (false);
		int Manth_Day[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int Year = std::atoi(BitcoinExchange::result[0].c_str());
		int Manth = std::atoi(BitcoinExchange::result[1].c_str());
		int Day = std::atoi(BitcoinExchange::result[2].c_str());
		
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
	//static void validateVector()
	//{
	//	std::string key;
	//	for (size_t i = 0; i < vec.size(); i++)
	//	{
	//		if (i % 2 == 0)
	//		{
	//			key = BitcoinExchange::vec[i];
	//			BitcoinExchange::splited = BitcoinExchange::splitString(key, '-');
	//			if (!BitcoinExchange::validateKey() || BitcoinExchange::vec[i].size() != 10)
	//				throw std::runtime_error("shat vata\n");	
	//		}
	//		else
	//			BitcoinExchange::validateValue(BitcoinExchange::vec[i], key);
	//	}
		
	//}
	// static void validateFile(std::string fName)
	// {
	// 	std::ifstream file(fName.c_str());
    // 	if (!file.is_open())
    //         throw std::runtime_error("Unable to open file");

    // 	std::string line;
    // 	std::string token;
	// 	std::string all;
    // 	std::stringstream ss;
		
    // 	while(std::getline(file, all))
	// 	{
	// 		line = all.substr(0, 10);
    // 		ss << line;
	// 		while (std::getline(ss, token, '-'))
	// 			vec.push_back(token);
	// 		BitcoinExchange::validateVector();
	// 		BitcoinExchange::badData();
	// 		BitcoinExchange::findComma(all, line);
	// 		ss.clear();
	// 		line.clear();
	// 		token.clear();
	// 		all.clear();
	// 		BitcoinExchange::vec.clear();
	// 	}
    // 	file.close(); 		
	// }
	// static void validateDbFile()
	// {
	// 	BitcoinExchange::validateFile("example.txt");
	// }
	static void validKeyValue()
	{
		if (BitcoinExchange::key.size() == 10 && BitcoinExchange::countOccurrences(BitcoinExchange::key, '-') == 2)
		{
			BitcoinExchange::splitString(BitcoinExchange::key, '-');
			if (!BitcoinExchange::validateKey())
				throw std::runtime_error("not valid!");
			BitcoinExchange::validateValue();
		}
		else
			throw std::runtime_error("not valid2!");
		//std::cout<<result->size();
	}
	static void openFile(std::string fname)
	{
		std::ifstream file(fname.c_str());
    	if (!file.is_open())
            throw std::runtime_error("Unable to open file\n");
		std::string line;
		size_t comma;
		std::getline(file, line);
		if (line != "date,exchange_rate")
			 throw std::runtime_error("Wrong db name\n");
		while (std::getline(file, line))
		{
			if ((comma = line.find(',')) == std::string::npos)
				throw std::runtime_error("Bad data1\n");
			BitcoinExchange::key = line.substr(0, comma);
			BitcoinExchange::value = line.substr(comma + 1, line.size());
			BitcoinExchange::validKeyValue();
		}
		//BitcoinExchange::validateVector();
		//BitcoinExchange::vec.clear();
		//BitcoinExchange::splited.clear();
			for (std::map<std::string, double>::iterator it = BitcoinExchange::map.begin(); it != map.end(); ++it) {
         std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    	 }
	}
	//static bool validateIntputValue(std::string& str, int i)
	//{
	//	if (!BitcoinExchange::is_all_num(str))
	//	{
	//		std::cout << "Error: bad input => " << BitcoinExchange::vec[i - 1] << " | " << BitcoinExchange::vec[i]<<std::endl;
	//		return (false);
	//	}
	//	if (str.size() > 4 || std::atoi(str.c_str()) > 1000)
	//	{
	//		std::cout<< "Error: too large a number."<<std::endl;
	//		return (false);
	//	}
		
	//	if (str.size() > 10 || std::atol(str.c_str()) < 0)
	//	{
	//		std::cout << "Error: not a positive number."<< std::endl;
	//		return (false);
	//	}
	//	return (true);
	//}
	//static void validateInputDate()
	//{
	//	std::string key;
	//	for (size_t i = 0; i < BitcoinExchange::vec.size(); i++)
	//	{
	//		if (i % 2 == 0)
	//		{
	//			key = BitcoinExchange::vec[i];
	//			BitcoinExchange::splited = BitcoinExchange::splitString(key, '-');
	//			if (!BitcoinExchange::validateKey() || BitcoinExchange::vec[i].size() != 10 || BitcoinExchange::vec[i+1].empty())
	//			{
	//					std::cout << "Error: bad input => "<<BitcoinExchange::vec[i]
	//					<<" | "<<BitcoinExchange::vec[i + 1]<<std::endl;	
	//					continue;
	//			}
	//			if(!BitcoinExchange::validateIntputValue(BitcoinExchange::vec[i+1], i+1))
	//				continue;

	//			std::map<std::string, double>::iterator it;
	//			it = BitcoinExchange::map.find(BitcoinExchange::vec[i]);
	//			if (it != BitcoinExchange::map.end())
	//			{
	//				std::cout<<BitcoinExchange::vec[i]<<" => "<< BitcoinExchange::vec[i + 1]<<" = "
	//				<<it->second * std::strtod(BitcoinExchange::vec[i + 1].c_str(), NULL) <<std::endl;
	//			}
	//			else
	//			{
	//				it = BitcoinExchange::map.upper_bound(BitcoinExchange::vec[i]);
	//				it--;
	//				std::cout<<BitcoinExchange::vec[i]<<" => "<< BitcoinExchange::vec[i + 1]<<" = "
	//				<<it->second * std::strtod(BitcoinExchange::vec[i + 1].c_str(), NULL) <<std::endl;
	//			}
	//		}
		
	
	//	}
	//}
	//static void validateInputFile(std::string fname)
	//{
	//	std::ifstream file(fname.c_str());
    //	if (!file.is_open())
    //        throw std::runtime_error("Unable to open file2\n");
	//	std::string line;
	//	size_t pipe;
	//	while (std::getline(file, line))
	//	{
	//		BitcoinExchange::removeSpaceTab(line);
	//		if ((pipe = line.find('|')) != std::string::npos)
	//		{
	//			BitcoinExchange::vec.push_back(line.substr(0, pipe));
	//			BitcoinExchange::vec.push_back(line.substr(pipe + 1, line.size()));
	//		}
	//		else
	//		{
	//			BitcoinExchange::vec.push_back(line.substr(0, 10));
	//			BitcoinExchange::vec.push_back(line.substr(10, line.size()));
	//		}
	//	}
	//	//BitcoinExchange::validateInputDate();
	//}
};

std::map<std::string, double> BitcoinExchange::map;
std::vector<std::string> BitcoinExchange::vec;
std::vector<std::string> BitcoinExchange::splited;
std::string BitcoinExchange::key;
std::string BitcoinExchange::value;
std::string BitcoinExchange::result[3];
#endif