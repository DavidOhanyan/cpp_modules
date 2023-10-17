/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:50:48 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/06 15:09:26 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/////////////////GETTERS////////////////
void Contact::set_name(std::string name)
{
	this->name = name;
}

void Contact::set_surname(std::string surname)
{
	this->surname = surname;
}

void Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

void Contact::set_number(std::string number)
{
	this->number = number;
}
/////////////SETERS///////////////////
std::string Contact::get_name()
{
	return (this->name);
}

std::string Contact::get_surname()
{
	return (this->surname);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_secret()
{
	return (this->secret);
}

std::string Contact::get_number()
{
	return (this->number);
}