/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/17 23:40:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc,  char **argv)
{
	try
	{
		if (argc == 1)
			throw std::runtime_error("Bad argument!");
		PmergeMe::validateFill(argv);

		for (size_t i = 0; i < PmergeMe::vec.size(); i++)
		{
				std::cout<<PmergeMe::vec[i] << " ";
		}
		std::cout<<std::endl;
	}
	catch(const std::exception& e)
	{
		PmergeMe::vec.clear();
		PmergeMe::lst.clear();
		std::cerr << e.what() << std::endl;
	}
	 

	return (0);
}
