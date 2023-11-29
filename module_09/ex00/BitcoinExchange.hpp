/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:21 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/29 21:06:53 by dohanyan         ###   ########.fr       */
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

class BitcoinExchange
{
private:
	static std::vector<std::string> vec;
	static std::map<std::string, double> map;
private:
	BitcoinExchange(){}
	BitcoinExchange(const BitcoinExchange& ){}
	BitcoinExchange& operator= (const BitcoinExchange& ){return (*this);}
	~BitcoinExchange(){}
public:
	static bool is_all_num(const std::string& line)
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (!std::isdigit(line[i]) && line[i] != '.')
				return (false);
		}
		return true;
	}
	static void badData()
	{
		//int Manth_Day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (size_t i = 0; i < BitcoinExchange::vec.size(); i++)
		{
			if (!BitcoinExchange::is_all_num(BitcoinExchange::vec[i]))
				throw std::runtime_error("bad number\n");
		}
		if (std::atoi(BitcoinExchange::vec[0].c_str()) < 2009 || std::atoi(BitcoinExchange::vec[0].c_str()) > 2024)
			throw std::runtime_error("high number\n");
		if (std::atoi(BitcoinExchange::vec[1].c_str()) < 1 || std::atoi(BitcoinExchange::vec[1].c_str()) > 12)
			throw std::runtime_error("high number2\n");
		if (std::atoi(BitcoinExchange::vec[2].c_str()) < 1 || std::atoi(BitcoinExchange::vec[2].c_str()) > 31)
			throw std::runtime_error("high number3\n");
		if (std::atoi(BitcoinExchange::vec[3].c_str()) < 1 || std::atoi(BitcoinExchange::vec[3].c_str()) > 1000 || BitcoinExchange::vec[3].size() > 4)
			throw std::runtime_error("high number3\n");
	}
	static void makeData()
	{
		std::string line;
		std::string token;
		std::stringstream ss;

		line = BitcoinExchange::vec[2];
		ss << line;
		BitcoinExchange::vec.pop_back();
		while (std::getline(ss, line, ','))
			BitcoinExchange::vec.push_back(line);
		badData();
		//std::vector<std::string>::iterator it = vec.begin();
		//while (it != vec.end())
		//{
		//	std::cout<<*it<<std::endl;
		//	it++;
		//}
		line.clear();
		token.clear();
		ss.clear();
	}
	static bool onlyOne(std::string line, char ch)
	{
		size_t first = line.find(ch);
		if (first != std::string::npos)
		{
			size_t second = line.find(ch, first + 1);
			if (second == std::string::npos)
				return (true);
		}
		return (false);
	}
	static bool canBeOne(std::string line, char ch)
	{
		size_t first = line.find(ch);
		if (first != std::string::npos)
		{
			size_t second = line.find(ch, first + 1);
			if (second == std::string::npos)
				return (true);
			return (false);
		}
		return (true);
	} 
	static void validateVector()
	{
		if (BitcoinExchange::vec.size() != 3)
			throw std::runtime_error("bad size1\n");
		if (BitcoinExchange::vec[0].size() != 4 || BitcoinExchange::vec[1].size() != 2 || BitcoinExchange::vec[2].size() < 4)
			throw std::runtime_error("bad size2\n");
		if (!BitcoinExchange::onlyOne(BitcoinExchange::vec[2], ',') || !BitcoinExchange::canBeOne(BitcoinExchange::vec[2], '.'))
			throw std::runtime_error("bad size3\n");
	}
	static void validateFile(std::string fName)
	{
		std::ifstream file(fName);
    	if (!file.is_open())
            throw std::runtime_error("Unable to open file");

    	std::string line;
    	std::string token;
    	std::stringstream ss;
		
    	while(std::getline(file, line))
		{
    		ss << line;
			while (std::getline(ss, token, '-'))
				vec.push_back(token);
			BitcoinExchange::validateVector();
			makeData();
			//storaket ov split u push map
			//BitcoinExchange::map[line] = 1.3;
			//std::map<std::string, double>::iterator it = BitcoinExchange::map.find(line);
			//std::cout<<it->first<<std::endl;
			//std::cout<<it->second<<std::endl;
			ss.clear();
			line.clear();
			token.clear();
			BitcoinExchange::vec.clear();
		}
    	file.close(); 		
	}

};

std::map<std::string, double> BitcoinExchange::map;
std::vector<std::string> BitcoinExchange::vec;

#endif