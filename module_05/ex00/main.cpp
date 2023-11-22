/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:20:13 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 22:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	try
	{
		Bureaucrat b1("b1",148);

		std::cout << b1 <<std::endl;
		b1.decrementGrade();
		std::cout << b1 <<std::endl;
		b1.decrementGrade();
		std::cout << b1 <<std::endl;
		b1.decrementGrade();
		std::cout << b1 <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// try
	// {
	// 	Bureaucrat b2("b2",3);

	// 	std::cout << b2 <<std::endl;
	// 	b2.decrementGrade();
	// 	std::cout << b2 <<std::endl;
	// 	b2.decrementGrade();
	// 	std::cout << b2 <<std::endl;
	// 	b2.decrementGrade();
	// 	std::cout << b2 <<std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try
	// {
	// 	Bureaucrat b3("b3",134);

	// 	std::cout << b3 <<std::endl;
	// 	b3.decrementGrade();
	// 	std::cout << b3 <<std::endl;
	// 	b3.decrementGrade();
	// 	std::cout << b3 <<std::endl;
	// 	b3.decrementGrade();
	// 	std::cout << b3 <<std::endl;
	// 	b3.incrementGrade();
	// 	std::cout << b3 <<std::endl;
	// 	b3.incrementGrade();
	// 	std::cout << b3 <<std::endl;
	// 	b3.incrementGrade();
	// 	std::cout << b3 <<std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	return (0);
}