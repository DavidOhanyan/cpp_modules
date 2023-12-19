/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:59 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/19 15:09:43 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error(ERR_BAD_ARG);
		if (std::string(argv[1]).find_first_not_of(' ') == std::string::npos)
			throw std::runtime_error(ERR_BAD_INPUT);
		RPN::pars(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<std::endl;
	}
 	return (0);
}