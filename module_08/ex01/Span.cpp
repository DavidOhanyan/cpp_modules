/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:07:51 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/25 22:18:51 by dohanyan         ###   ########.fr       */
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
		throw std::out_of_range("lol!");
}

int Span::shortestSpan()
{
	std::list<int>::iterator it;
	if (this->lst.empty() || this->lst.size() == 1)
		throw std::runtime_error("time");
	this->lst.sort();
	for (it = this->lst.begin(); it != this->lst.end(); ++it) {
        std::cout << *it << " ";
    }
	return 0;
}

int Span::longestSpan()
{
	std::list<int>::iterator max = std::max_element(this->lst.begin(), this->lst.end());
	std::list<int>::iterator min = std::min_element(this->lst.begin(), this->lst.end());
	if (this->lst.empty() || this->lst.size() == 1)
		throw std::runtime_error("time");
	return (*max - *min);
}
