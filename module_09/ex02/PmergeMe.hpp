/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:44:40 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/14 22:47:53 by dohanyan         ###   ########.fr       */
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
public:
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
			//if (line.size() == 0)
			//	throw std::runtime_error("Error8");
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
			if (VecStr[i].size() <= 10 && std::atol(VecStr[i].c_str()) > -2147483648 && std::atol(VecStr[i].c_str()) < 2147483647)
			{
				PmergeMe::vec.push_back(std::atoi(VecStr[i].c_str()));
				PmergeMe::lst.push_back(std::atoi(VecStr[i].c_str()));
			}
			else
				throw std::runtime_error("Error4");
		}
		
	}
	static void validateFill(char **argv)
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
/////////////////////////
	static void merge (std::vector<std::pair<int, int> > &leftFirst, std::vector<std::pair<int, int> > &rightFirst, std::vector<std::pair<int, int> > &arr)
	{
		int leftSize = arr.size() / 2;
		int rightSize = arr.size() - leftSize;
	
		int l = 0;
		int r = 0;
		int i = 0;
	
	
		while (l < leftSize && r < rightSize)
		{
			if (leftFirst[l].first < rightFirst[r].first)
			{
				arr[i].first = leftFirst[l].first;
				i++;
				l++;
			}
			else
			{
				arr[i].first = rightFirst[r].first;
				i++;
				r++;
			}
		}
		while (l < leftSize)
		{
			arr[i].first = leftFirst[l].first;
			i++;
			l++;
		}
		while (r < rightSize)
		{
			arr[i].first = rightFirst[r].first;
			i++;
			r++;
		}
	}
	static void mergeSort(std::vector<std::pair<int, int> > &pair)
	{
		int lenght = pair.size();
		if (lenght <= 1)
			return ;
		int middle = pair.size() / 2;
	
		std::vector<std::pair<int, int> > leftFirst(middle);
		std::vector<std::pair<int, int> > rightFirst(pair.size() - middle);
		int i = 0;
		int j = 0;
		for (; i < lenght; i++)
		{
			if (i < middle)
				leftFirst[i] = pair[i];
			else
			{
				rightFirst[j] = pair[i];
				j++;
			}		
		}
		PmergeMe::mergeSort(leftFirst);
		PmergeMe::mergeSort(rightFirst);
		PmergeMe::merge(leftFirst, rightFirst, pair);
	}


	static void fillCorrectPair(std::vector<std::pair<int, int> > &pair)
	{
		if (PmergeMe::vec.size() % 2 != 0)
			PmergeMe::vec.push_back(0);
		for (size_t i = 0; i < PmergeMe::vec.size();)
		{
			if (PmergeMe::vec[i + 1] > PmergeMe::vec[i])
				pair.push_back(std::make_pair(PmergeMe::vec[i + 1], PmergeMe::vec[i]));
			else
				pair.push_back(std::make_pair(PmergeMe::vec[i], PmergeMe::vec[i + 1]));
			i+=2;
		}
	}
};

std::vector<int> PmergeMe::vec;
std::list<int> PmergeMe::lst;

#endif