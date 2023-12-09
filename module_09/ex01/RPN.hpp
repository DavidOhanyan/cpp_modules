/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:03:50 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/10 01:18:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <iostream>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <cmath>

class RPN
{
private:
    static std::stack<double> stack;
private:
    RPN();
	RPN(const RPN&);
	RPN& operator= (const RPN&);
	~RPN();
public:
    static void removeSpaces(std::string &str);
    static void pars(std::string line);
    static void fill(std::string &line);
    static void calc(const char in);
};

#endif