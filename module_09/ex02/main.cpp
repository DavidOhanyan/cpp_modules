/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/17 19:06:22 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc,  char **argv)
{
	try
	{
		if (argc == 1)
			throw std::runtime_error("Bad argument!");
		std::vector<std::pair<int, int> > y_vec;
		std::vector<std::pair<int, int> > pair;
		
		PmergeMe::validateFill(argv);
		PmergeMe::fillCorrectPair(pair);

		PmergeMe::mergeSort(pair);
		PmergeMe::takeOutFirst(pair);
		PmergeMe::takeOutSecond(pair, y_vec);
		PmergeMe::correct_y_vec(pair, y_vec);
		PmergeMe::BinaryInsert(y_vec);
		for (size_t i = 0; i < PmergeMe::vec.size(); i++)
		{
				std::cout<<PmergeMe::vec[i] << " ";
		}
	}
	catch(const std::exception& e)
	{
		PmergeMe::vec.clear();
		PmergeMe::lst.clear();
		std::cerr << e.what() << std::endl;
	}
	 

	return (0);
}
