/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:44:40 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/13 21:02:14 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGEME_HPP_
#define _PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <list>

class PmergeMe
{
private:
	static std::vector<int> vec;
	static std::list<int> lst;
private:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator= (const PmergeMe&);
	~PmergeMe();
public:
	static std::string stringAssembly(char **argv)
	{
		int i = 0;
		std::string line;
		
		while (argv[++i])
		{
			line += argv[i];
			line += " ";
		}
		return (line);
	}
	static void hasDuplicates(const std::vector<std::string>& VecStr)
	{
    	std::vector<std::string> sortedStrings = VecStr;
    	std::sort(sortedStrings.begin(), sortedStrings.end());
	
    	for (size_t i = 0; i < sortedStrings.size() - 1; ++i) 
		{
    	    if (sortedStrings[i] == sortedStrings[i + 1])
				throw std::runtime_error("Error3");
    	}
	}
	static void isValidInput(const std::vector<std::string>& VecStr)
	{
		size_t i = 0;
		size_t j = 0;
		while (i < VecStr.size())
		{
			j = 0;
			if (VecStr[i].size() == 1 && VecStr[i] == "0")
				throw std::runtime_error("Error1");
			while (j < VecStr[i].size())
			{
				if (!std::isdigit(VecStr[i][j]))
					throw std::runtime_error("Error2");
				j++;
			}
			i++;
		}
	}
	static void fillContainer(const std::vector<std::string>& VecStr)
	{
		for (size_t i = 0; i < VecStr.size(); i++)
		{
			if (VecStr[i].size() <= 10 && std::atol(VecStr[i].c_str()) > -2147483648))
		}
		
	}
	static void validateInput(char **argv)
	{
		std::string line;
		std::vector<std::string> VecStr;
		std::stringstream ss;
		
		line = stringAssembly(argv);
		ss << line;
		line.clear();
		while (std::getline(ss, line, ' '))
		{
			if (!line.empty())
				VecStr.push_back(line);
		}
		PmergeMe::isValidInput(VecStr);
		PmergeMe::hasDuplicates(VecStr);
		PmergeMe::fillContainer(VecStr);
	}
};

std::vector<int> PmergeMe::vec;
std::list<int> PmergeMe::lst;

#endif