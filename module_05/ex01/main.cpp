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
		Bureaucrat b1("b1", 13);
		std::cout << b1 <<std::endl;
		Form f1("b1", 15, 36);
		std::cout << f1 <<std::endl;
		f1.beSigned(b1);
		std::cout << f1 <<std::endl;
		b1.signForm(f1);
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what()<<std::endl;
	}
	std::cout<<std::endl;
	try
	{
		Bureaucrat b2("b1", 17);
		std::cout << b2 <<std::endl;
		Form f2("b1", 15, 36);
		std::cout << f2 <<std::endl;
		b2.signForm(f2);
		f2.beSigned(b2);
		std::cout << f2 <<std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what()<<std::endl;
	}
	return (0);
}