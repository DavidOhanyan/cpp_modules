/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:09:37 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/10 16:12:26 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool PhoneBook::parse_string(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]))
			return false;
	}
	return (true);
}

bool PhoneBook::parce_number(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (std::isalpha(str[i]) || str.length() != 9)
			return false;
	}
	return (true);
}

bool PhoneBook::space_case(std::string str)
{
	size_t i;
	
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
			break;
	}
	if (i == str.length()) 
		return (false);
	return (true);
}

void PhoneBook::make_word(std::string &print, std::string str2)
{
	if (str2.length() > 10)
		print = (str2.substr(0, 9) + '.');
	else
		print = str2;
}

void PhoneBook::add(int i)
{
	std::string str;

	while (1)
	{
		std::cout << "input name: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if (!parse_string(str) || str.empty() || !space_case(str))
		{
			std::cout<<std::endl;
			std::cout << "wrong name input."<<std::endl;
			std::cout<<std::endl;
			continue;
		}
		c1[i].set_name(str);
		break; 
	}	
	while(1)
	{
		std::cout << "input surname: ";
		getline(std::cin,str);
		if (std::cin.eof())
			exit(1);
		if (!parse_string(str) || str.empty() || !space_case(str))
		{
			std::cout<<std::endl;
			std::cout << "wrong surname input."<<std::endl;
			std::cout<<std::endl;
			continue;
		}
		c1[i].set_surname(str);
		break;
	}
	while (1)
	{
		std::cout << "input phone number: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		if(!parce_number(str) || str.empty() || !space_case(str))
		{
			std::cout<<std::endl;
			std::cout << "wrong number input."<<std::endl;
			std::cout<<std::endl;
			continue;
		}
		c1[i].set_number(str);
		break;
	}

	std::cout << "input nickname: ";
	getline(std::cin,str);
	if (std::cin.eof())
			exit(1);
	c1[i].set_nickname(str);
	
	std::cout << "input darkest secret: ";
	getline(std::cin,str);
	if (std::cin.eof())
			exit(1);
	c1[i].set_secret(str);

	std::cout << std::endl;
	std::cout << "you have successfully add new contact. " << std::endl << std::endl;
}

void PhoneBook::search(int count)
{
	std::string temp;
	std::string print;
	int index = 0;
	
	std::cout << std::endl;
	std::cout << "|  index   |   name   | surname  | nickname |" << std::endl;
	for (int k = 0; k < count; k++)
	{
		std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
		std::cout << "|"<< std::setw(10) << k << "|" << std::setw(10); 
		make_word(print, c1[k].get_name());
		std::cout << print << "|" << std::setw(10);
		make_word(print, c1[k].get_surname());
		std::cout << print << "|" << std::setw(10);
		make_word(print, c1[k].get_nickname());
		std::cout << print << "|" <<std::endl;
	}
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl << std::endl; 
	if (count != 0)
	{
		while(1)
		{ 
			std::cout << "input index for more information: ";
			std::getline(std::cin, temp);
			if (std::cin.eof())
				exit(1);
			index = std::atoi(temp.c_str());
			if(index >= count || temp.empty() || std::isalpha(temp[0]) || index < 0 || !space_case(temp))
			{
				std::cout << "wrong index input." << std::endl;
				continue;
			}
			std::cout << std::endl;
			break;
		}
		std::cout << "name -> " << c1[index].get_name() << std::endl;
		std::cout << "surname -> " << c1[index].get_surname() << std::endl;
		std::cout << "number -> " << c1[index].get_number() << std::endl;
		std::cout << "nickname -> " << c1[index].get_nickname() << std::endl;
		std::cout << "secret -> " << c1[index].get_secret() << std::endl;
		std::cout << std::endl;
	}
}