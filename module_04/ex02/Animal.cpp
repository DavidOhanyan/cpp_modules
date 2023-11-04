/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:46 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 16:15:54 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{	
	std::cout << "Default Animal Constructor" << std::endl;
	this->type = "unknown";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy Animal Constructor" << std::endl;
	this->type = other.type;
}

Animal &Animal::operator = (const Animal &other)
{
	std::cout << "Operator Assignment Animal" << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	return (*this);
}

Animal::~Animal()	
{
	std::cout << "Destructor Animal" << std::endl;
}

void Animal::setType(const std::string &type)
{	
	std::cout << "Set Animal Function" <<std::endl;
	this->type = type;
}

std::string Animal::getType() const
{
	std::cout << "Get Animal Function" <<std::endl;
	return (this->type);
}