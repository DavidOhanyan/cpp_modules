/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:07:51 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/27 13:26:35 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():N(0)
{}

Span:: Span(unsigned int sz):N(sz)
{}

Span::Span(const Span& other)
{
    this->N = other.N;
    this->lst = other.lst;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->lst = other.lst;
    }
	return (*this);
}

Span::~Span(){}

void Span::addNumber(const int num)
{
	if (this->lst.size() < this->N)
	{
		this->lst.push_back(num);
	}
	else
		throw std::out_of_range("out of rang!");
}

int Span::shortestSpan()
{
	int min = *std::max_element(this->lst.begin(), this->lst.end());
	if (this->lst.empty() || this->lst.size() == 1)
		throw std::runtime_error("your Span is to short!");
	std::list<int> newLst = this->lst;
	newLst.sort();
	std::list<int>::iterator it1 = newLst.begin();
	std::list<int>::iterator it2 = ++newLst.begin();
	for (; it1 != --newLst.end(); it1++)
	{
		if ((*it2 - *it1) < min)
			min = (*it2 - *it1);
		it2++;
	}
	return (min);
}

int Span::longestSpan()
{
	std::list<int>::iterator max = std::max_element(this->lst.begin(), this->lst.end());
	std::list<int>::iterator min = std::min_element(this->lst.begin(), this->lst.end());
	if (this->lst.empty() || this->lst.size() == 1)
		throw std::runtime_error("your Span is to short!");
	return (*max - *min);
}

void Span::fill(unsigned int size)
{
	if (size + this->lst.size() > this->N)
		throw std::runtime_error("dont do that!");
	while (size--)
	{
		this->lst.push_back(size);
	}
}
