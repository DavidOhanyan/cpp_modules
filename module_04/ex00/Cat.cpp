/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 19:32:13 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat Constructor" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other): Animal(other)
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

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow"<< std::endl;
}

