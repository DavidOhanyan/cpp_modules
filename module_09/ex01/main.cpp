/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:59 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/10 00:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("bad input");
		RPN::pars(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	
	
	// std::stack<double> s1;
	// s1.push(1);
	// s1.push(2);
	// s1.push(3);
	// s1.push(4);
	// std::cout << s1.top() << std::endl;
	// s1.pop();
	// std::cout << s1.top() << std::endl;
 	return (0);
}