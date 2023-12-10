/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:59 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/10 15:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error(ERR_BAD_ARG);
		RPN::pars(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<std::endl;
	}
 	return (0);
}