/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/29 17:05:23 by dohanyan         ###   ########.fr       */
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

	try
	{
		BitcoinExchange::validateFile("example.txt");
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what();
	}
	return(0);
}