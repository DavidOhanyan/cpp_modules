/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:10:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/19 14:21:20 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
	try
	{
		if (argc != 2)
			throw std::runtime_error(ERR_WRONG_ARG);
		BitcoinExchange::dbFile("data.csv");
		BitcoinExchange::infile(argv[1]);
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return(0);
}