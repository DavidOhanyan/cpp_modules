/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:22:21 by marvin            #+#    #+#             */
/*   Updated: 2023/12/08 00:22:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN& ){}
RPN& RPN::operator= (const RPN& ){return (*this);}
RPN::~RPN(){}

void RPN::removeSpaces(std::string &str) 
{
	std::string::iterator iter = str.begin();
	while (iter != str.end()) 
	{
        if (std::isspace(*iter)) 
            iter = str.erase(iter);
	    else
            ++iter;
	}
}

void RPN::pars(std::string line)
{
    std::string rem;

    rem = line;
    RPN::removeSpaces(line);
    for (size_t i = 0; i < rem.size(); i++)
    {
        if (std::isdigit(rem[i]) && std::isdigit(rem[i + 1]))
            throw std::runtime_error(ERR_BAD_INPUT);
        if ((rem[i] == '+' || rem[i] == '-' || rem[i] == '*' ||  rem[i] == '/') && std::isdigit(rem[i + 1]))
            throw std::runtime_error(ERR_BAD_INPUT);
    }
    
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!std::isdigit(line[i]) && line[i] != '-' && line[i] != '+' && line[i] != '*' && line[i] != '/')
            throw std::runtime_error(ERR_BAD_INPUT);
    }
    RPN::fill(line);
}

void RPN::fill(std::string &line)
{
    RPN::removeSpaces(line);
    for (size_t i = 0; i < line.size(); i++)
    {
        if (std::isdigit(line[i]))
            RPN::stack.push(std::atoi(line.substr(i, 1).c_str()));
        else
            if(!std::isdigit(line[i]) && RPN::stack.size() > 1)
                RPN::calc(line[i]);
        else
            throw std::runtime_error(ERR_BAD_INPUT);
    }
    if (RPN::stack.size() > 1)
        throw std::runtime_error(ERR_BAD_INPUT);
    std::cout << "Result: " << RPN::stack.top() << std::endl;
}

void RPN::calc(const char in)
{
    double rv, lv;

    rv = RPN::stack.top();
    RPN::stack.pop();
    lv = RPN::stack.top();
    RPN::stack.pop();
    switch (in)
    {
        case '+':
            RPN::stack.push(lv + rv);
            break;
        case '-':
            RPN::stack.push(lv - rv);
            break;
        case '*':
            RPN::stack.push(lv * rv);
            break;
        case '/':
            RPN::stack.push(lv / rv);
            break;
    }
}

std::stack<double> RPN::stack;
