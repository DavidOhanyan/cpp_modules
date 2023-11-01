/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:42:11 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:55 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default Dog Constructor" << std::endl;
	this->brain = new Brain;
	this->type = "Dog";
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Copy Dog Constructor" << std::endl;
	this->type = other.type;
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i), i);
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Operator Assignment Dog" << std::endl;
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

Dog::~Dog()
{
	std::cout << "Destructor Dog" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Meow Meow Meow"<< std::endl;
}

