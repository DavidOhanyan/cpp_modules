/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:44:40 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/17 19:07:52 by dohanyan         ###   ########.fr       */
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
#include <cmath>


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
			if (std::string(argv[i]).find_first_not_of(' ') == std::string::npos)
				throw std::runtime_error("Error8");
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
				arr[i] = leftFirst[l];
				i++;
				l++;
			}
			else
			{
				arr[i] = rightFirst[r];
				i++;
				r++;
			}
		}
		while (l < leftSize)
		{
			arr[i] = leftFirst[l];
			i++;
			l++;
		}
		while (r < rightSize)
		{
			arr[i] = rightFirst[r];
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

	static void takeOutFirst(std::vector<std::pair<int, int> > &pair)
	{
		PmergeMe::vec.clear();
		PmergeMe::vec.push_back(pair[0].second);
		for (size_t i = 0; i < pair.size(); i++)
			PmergeMe::vec.push_back(pair[i].first);
	}

	static void takeOutSecond(std::vector<std::pair<int, int> > &pair, std::vector<std::pair<int, int> >& y_vec)
	{
		int j = 3;
		for (size_t i = 1; i < pair.size(); i++)
		{
			y_vec.push_back(std::make_pair(pair[i].second, j));
			j++;	
		}
	}

	static void correct_y_vec(std::vector<std::pair<int, int> > &pair, std::vector<std::pair<int, int> >& y_vec)
	{
		int i = 1;
		size_t last;
		size_t var = 2;
		std::vector<std::pair<int, int> >::iterator start = y_vec.begin();
		std::vector<std::pair<int, int> >::iterator end = y_vec.end();
		while (var <= pair.size() + 2)
		{
			size_t dist = std::distance(start, end);
			i++;
			last = var;
			var = std::pow(2, i) - last;
			if (last < dist)
			{
				std::reverse(start, start + last);
			}
			else
			{
				std::reverse(start, end);
				break;
			}
			start += last;
		}
	}
	static void BinaryInsert(std::vector<std::pair<int, int> >& y_vec)
	{
		int numIterations = 0;
		for (size_t i = 0; i < y_vec.size(); i++)
		{
			std::vector<int>::iterator it = std::lower_bound(PmergeMe::vec.begin(),(PmergeMe::vec.begin() + y_vec[i].second + numIterations), y_vec[i].first);
			PmergeMe::vec.insert(it, y_vec[i].first);
			numIterations++;
		}
		std::vector<int>::iterator it = std::find(PmergeMe::vec.begin(), PmergeMe::vec.end(), 0);
    	if (it != PmergeMe::vec.end())
        	PmergeMe::vec.erase(it);
	}
	
};

std::vector<int> PmergeMe::vec;
std::list<int> PmergeMe::lst;
#endif