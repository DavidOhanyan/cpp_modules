/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/01 20:07:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//#include <pair>



int main() 
{
	//std::string s1="2001-01-01,1";
	//std::string token;
	//std::vector<std::string> vs;
	//std::stringstream ss;
	//ss << s1;
	//std::string input;
	//std::getline(ss, token, '-');
	//std::cout<<token<<std::endl;
	//std::getline(ss, token, '-');
	//std::cout<<token<<std::endl;
	//std::cout<<token<<std::endl;
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.

// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.33
// Error: not a positive number.
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
	try
	{
		BitcoinExchange::validateDb("data.csv");
		BitcoinExchange::validateInputFile("input.txt");
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what();
	}
	return(0);
}