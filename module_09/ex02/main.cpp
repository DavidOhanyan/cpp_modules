/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/18 20:30:54 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc,  char **argv)
{
	try
	{
		if (argc == 1)
			throw std::runtime_error("Bad argument!");
		PmergeMe::validateAndFill(argv);
		PmergeMe::SortAndTime();
	}
	catch(const std::exception& e)
	{
		PmergeMe::vec.clear();
		PmergeMe::lst.clear();
		std::cerr << e.what() << std::endl;
	}
	 

	return (0);
}
