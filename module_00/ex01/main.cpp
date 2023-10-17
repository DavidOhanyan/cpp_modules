/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:04 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/06 14:54:33 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook b1;
	std::string input;
	
	int i = 0;
	int count = 0;
	while (1)
	{
		std::cout << "command -> ADD: adding new contact. " << std::endl;
		std::cout << "command -> SEARCH: searching and showing contacts. " << std::endl;
		std::cout << "command -> EXIT: closing programm. " << std::endl << std::endl;
		std::cout << "input command: ";
		std::getline(std::cin, input);
		if(std::cin.eof())
		{
			std::cout<<std::endl;
			std::cout<<"do not press ctrl D"<<std::endl;
			break;
		}
		if (input == "ADD")
		{
			b1.add(i);
			i++;
			if (count < 8)
				count++;
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH")
			b1.search(count);
		else if (input == "EXIT")
			break;
		else
			std::cout << "Wrong input, try again!"<<std::endl;
	}
	return (0);	
}