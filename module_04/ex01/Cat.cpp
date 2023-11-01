/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:04 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default Cat Constructor" << std::endl;
	this->brain = new Brain;
	this->type = "Cat";
}

Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Copy Cat Constructor" << std::endl;
	this->type = other.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i), i);
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Operator Assignment Cat" << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i), i);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Cat" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow"<< std::endl;
}

