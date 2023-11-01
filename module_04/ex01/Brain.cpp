/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:50:59 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 20:24:39 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{	
	std::cout << "Default Brain Constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy Brain Constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << "Operator Assignment Brain" << std::endl;
	if (this == &other)
		return(*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()	
{
	std::cout << "Destructor Brain" << std::endl;
}

void Brain::setIdea(const std::string &idea, const int &index)
{	
	std::cout << "Set Brain Function" <<std::endl;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(const int &index) const
{
	std::cout << "Get Brain Function" <<std::endl;
	return (this->ideas[index]);
}