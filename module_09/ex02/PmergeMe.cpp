/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:15:45 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/18 20:30:10 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& ){}
PmergeMe& PmergeMe::operator= (const PmergeMe& ){return (*this);}
PmergeMe::~PmergeMe(){}

std::string PmergeMe::stringAssembly(char **argv)
{
	int i = 0;
	std::string line;
	
	while (argv[++i])
	{
		line += argv[i];
		if (std::string(argv[i]).find_first_not_of(' ') == std::string::npos)
			throw std::runtime_error(ERROR);
		line += " ";
	}
	return (line);
}
	
void PmergeMe::hasDuplicates(const std::vector<std::string>& VecStr)
{
	std::vector<std::string> sortedStrings = VecStr;
	std::sort(sortedStrings.begin(), sortedStrings.end());

	for (size_t i = 0; i < sortedStrings.size() - 1; ++i) 
	{
	    if (sortedStrings[i] == sortedStrings[i + 1])
			throw std::runtime_error(ERROR);
	}
}
	
void PmergeMe::isValidInput(const std::vector<std::string>& VecStr)
{
	size_t i = 0;
	size_t j = 0;
	while (i < VecStr.size())
	{
		j = 0;
		if (VecStr[i].size() == 1 && VecStr[i] == "0")
			throw std::runtime_error(ERROR);
		while (j < VecStr[i].size())
		{
			if (!std::isdigit(VecStr[i][j]))
				throw std::runtime_error(ERROR);
			j++;
		}
		i++;
	}
}

void PmergeMe::fillContainer(const std::vector<std::string>& VecStr)
{
	for (size_t i = 0; i < VecStr.size(); i++)
	{
		if (VecStr[i].size() <= 10 && std::atol(VecStr[i].c_str()) > -2147483648 && std::atol(VecStr[i].c_str()) < 2147483647)
		{
			PmergeMe::vec.push_back(std::atoi(VecStr[i].c_str()));
			PmergeMe::lst.push_back(std::atoi(VecStr[i].c_str()));
		}
		else
			throw std::runtime_error(ERROR);
	}
	
}
	
void PmergeMe::validateAndFill(char **argv)
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
	
template<typename Container>
void PmergeMe::merge (Container &leftFirst, Container &rightFirst,Container &arr)
{
	typename Container::iterator leftIter = leftFirst.begin();
	typename Container::iterator rightIter = rightFirst.begin();
	typename Container::iterator arrIter = arr.begin();

	while (leftIter != leftFirst.end() && rightIter != rightFirst.end())
	{
		if ((*leftIter).first < (*rightIter).first)
		{
			*arrIter = *leftIter;
			arrIter++;
			leftIter++;
		}
		else
		{
			*arrIter = *rightIter;
			arrIter++;
			rightIter++;
		}
	}
	while (leftIter != leftFirst.end())
	{
		*arrIter = *leftIter;
		arrIter++;
		leftIter++;
	}
	while (rightIter != rightFirst.end())
	{
		*arrIter = *rightIter;
		arrIter++;
		rightIter++;
	}
}
	
template<typename Container>
void PmergeMe::mergeSort(Container &pair)
{
	int lenght = pair.size();
	if (lenght <= 1)
		return ;
	
	Container leftFirst;
	Container rightFirst;
	typename Container::iterator it_begin = pair.begin();
	typename Container::iterator it_end = pair.end();
		
	typename Container::iterator it_middle = it_begin;
		
	std::advance(it_middle, std::distance(it_begin, it_end) / 2);

	for (typename Container::iterator it = it_begin; it != it_middle; ++it)
	    leftFirst.push_back(*it);

    for (typename Container::iterator it = it_middle; it != it_end; ++it)
		rightFirst.push_back(*it);

	PmergeMe::mergeSort(leftFirst);
	PmergeMe::mergeSort(rightFirst);
	PmergeMe::merge(leftFirst, rightFirst, pair);
}

template<typename Container>
void PmergeMe::fillCorrectPair(Container &pair)
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

template<typename Container>
void PmergeMe::takeOutFirst(Container &pair)
{
	typename Container::iterator it = pair.begin();
	PmergeMe::vec.clear();
	PmergeMe::vec.push_back(it->second);
	for (; it != pair.end(); it++)
		PmergeMe::vec.push_back(it->first);
}

template<typename Container>
void PmergeMe::takeOutSecond(Container &pair, Container& y_vec)
{
	int j = 2;
	typename Container::iterator it = ++pair.begin();
	for (; it != pair.end(); it++)
	{
		y_vec.push_back(std::make_pair(it->second, j));
		j++;	
	}
}

template<typename Container>
void PmergeMe::correct_y_vec(Container &pair, Container & y_vec)
{
	int i = 1;
	size_t last;
	size_t var = 2;
	typename Container::iterator start = y_vec.begin();
	typename Container::iterator end = y_vec.end();
	while (var <= pair.size() + 2)
	{
		size_t dist = std::distance(start, end);
		i++;
		last = var;
		var = std::pow(2, i) - last;
		if (last < dist)
		{
			typename Container::iterator temp = start;
			std::advance(temp, last);
			std::reverse(start, temp);
		}
		else
		{
			std::reverse(start, end);
			break;
		}
		for (size_t j = 0; j < last; ++j)
    		++start;
	}
}

template<typename Container>
void PmergeMe::BinaryInsert(Container & y_vec)
{
	typename Container::iterator iter = y_vec.begin();
	int numIterations = 0;
	for (; iter != y_vec.end(); iter++)
	{
		std::vector<int>::iterator it = std::lower_bound(PmergeMe::vec.begin(),(PmergeMe::vec.begin() + iter->second + numIterations), iter->first);
		PmergeMe::vec.insert(it, iter->first);
		numIterations++;
	}
	std::vector<int>::iterator it = std::find(PmergeMe::vec.begin(), PmergeMe::vec.end(), 0);
    if (it != PmergeMe::vec.end())
    PmergeMe::vec.erase(it);
}
	
void PmergeMe::SortAndTime()
{
	PmergeMe::print_container("Before: ");
		
	checkTime(&PmergeMe::sortContainer<std::vector<std::pair<int, int> > >, "Vector");
	PmergeMe::print = false;
	checkTime(&PmergeMe::sortContainer<std::list<std::pair<int, int> > >, "List");
	PmergeMe::vec.clear();
	PmergeMe::lst.clear();
}

template <typename Container>
void PmergeMe::sortContainer()
{
	Container y_vec;
	Container pair;
	
	PmergeMe::fillCorrectPair(pair);
	PmergeMe::mergeSort(pair);
	PmergeMe::takeOutFirst(pair);
	PmergeMe::takeOutSecond(pair, y_vec);
	PmergeMe::correct_y_vec(pair, y_vec);
	PmergeMe::BinaryInsert(y_vec);
	
	y_vec.clear();
	pair.clear();
}
	
void PmergeMe::print_container(const std::string & addnText ) 
{
	std::cout << addnText;
	for (size_t i = 0; i < PmergeMe::vec.size(); i++)
		std::cout << PmergeMe::vec[i] << " ";
	
	std::cout << std::endl;
}
	
void PmergeMe::checkTime(void(*foo)(), std::string container) 
{
	struct timeval start_time, end_time;

	gettimeofday(&start_time, NULL);
	foo();
	gettimeofday(&end_time, NULL);

	long duration = (end_time.tv_sec - start_time.tv_sec) * 1000000L + (end_time.tv_usec - start_time.tv_usec);

	if (PmergeMe::print)
		PmergeMe::print_container("After: ");

	std::cout << "Time to process a range of " << PmergeMe::vec.size() << " elements with " 
		<< container << ": " << duration << "us" << std::endl;
}

std::vector<int> PmergeMe::vec;
std::list<int> PmergeMe::lst;
bool PmergeMe::print = true;