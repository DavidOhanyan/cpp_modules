/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:16:46 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/14 15:39:01 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "The memory address of the string variable -> " << &str << std::endl;
	std::cout << "The memory address held by stringPTR -> " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF -> " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable -> " << str <<std::endl;
	std::cout << "The value pointed to by stringPTR -> " << *stringPTR <<std::endl;
	std::cout << "The value pointed to by stringREF -> " << stringREF <<std::endl;
	return (0);
}