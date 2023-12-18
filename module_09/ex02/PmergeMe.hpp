/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:44:40 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/18 20:29:31 by dohanyan         ###   ########.fr       */
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
#include <algorithm>
#include <ctime>
#include <sys/time.h>

#define ERROR "Error"


class PmergeMe
{
public:
	static std::vector<int> vec;
	static std::list<int> lst;
	static bool print;
private:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator= (const PmergeMe&);
	~PmergeMe();
public:
	static void validateAndFill(char **argv);
	static void SortAndTime();
private:
	static std::string stringAssembly(char **argv);
	static void hasDuplicates(const std::vector<std::string>& VecStr);
	static void isValidInput(const std::vector<std::string>& VecStr);
	static void fillContainer(const std::vector<std::string>& VecStr);
	template<typename Container>
	static void merge (Container &leftFirst, Container &rightFirst,Container &arr);
	template<typename Container>
	static void mergeSort(Container &pair);
	template<typename Container>
	static void fillCorrectPair(Container &pair);
	template<typename Container>
	static void takeOutFirst(Container &pair);
	template<typename Container>
	static void takeOutSecond(Container &pair, Container& y_vec);
	template<typename Container>
	static void correct_y_vec(Container &pair, Container & y_vec);
	template<typename Container>
	static void BinaryInsert(Container & y_vec);
	template <typename Container>
	static void sortContainer();
	static void print_container(const std::string & addnText );
	static void checkTime(void(*foo)(), std::string container);
};

#endif