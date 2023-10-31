/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:42:11 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/31 21:02:41 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog Constructor" << std::endl;
	this->type = "unknown";
}

Dog::Dog(const std::string &tp):Animal(tp)
{
	std::cout << "Parametr Dog Constructor" << std::endl;	
	this->type = tp;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy Dog Constructor" << std::endl;
	this->type = other.type;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Operator Assignment Dog" << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof Woof"<< std::endl;
}
