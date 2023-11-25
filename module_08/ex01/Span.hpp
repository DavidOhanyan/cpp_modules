/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:31:51 by tumolabsstu       #+#    #+#             */
/*   Updated: 2023/11/26 01:55:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <list>
#include <algorithm>

class Span
{
private:
    unsigned int N;
    std::list<int> lst;
public:
    Span();
    Span(unsigned int sz);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(const int num);

    int shortestSpan();
    int longestSpan();
    
    void fill(unsigned int size);
};

#endif