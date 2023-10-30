/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/30 21:41:02 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat Constructor" << std::endl;
	this->type = "unknown";
}

Cat::Cat(const std::string &tp)
{
	std::cout << "Parametr Cat Constructor" << std::endl;	
	this->type = tp;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy Cat Constructor" << std::endl;
	this->type = other.type;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Operator Assignment Cat" << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat" << std::endl;
}

void Cat::set_type(const std::string &type)
{	
	std::cout << "Set Cat Function" <<std::endl;
	this->type = type;
}

std::string Cat::get_type() const
{
	std::cout << "Set Cat Function" <<std::endl;
	return (this->type);
}