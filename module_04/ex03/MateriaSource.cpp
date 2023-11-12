/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:48:11 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/10 13:37:25 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default MateriaSource Constructor." << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy MateriaSource Constructor." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->slots[i];
		this->slots[i] = other.slots[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Operator Assignment MateriaSource." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->slots[i];
			this->slots[i] = other.slots[i]->clone();
		}
	}
	return(*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor MateriaSource." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->slots[i];
		this->slots[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->slots[i] == materia)
			return;
		if (!this->slots[i])
		{
			this->slots[i] = materia;
			std::cout << "MateriaSource learned." << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource can't learn." << std::endl;
	
}

AMateria* MateriaSource::createMateria (std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->slots[i] && this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	return (NULL);
}