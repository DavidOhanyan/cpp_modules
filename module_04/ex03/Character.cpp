/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:20:18 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/10 13:39:06 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Default Character Constructor." << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(const std::string &name):_name(name)
{
	std::cout << "Parametr Character Constructor." << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(const Character &other)
{	
	std::cout << "Copy Character Constructor." << std::endl;
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		delete this->slots[i];
		this->slots[i] = other.slots[i]->clone();
	}
}

Character& Character::operator=(const Character &other)
{
	std::cout << "Operator Assignment Character." << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->slots[i];
			this->slots[i] = other.slots[i]->clone();
		}
	}
	return(*this);
}

Character::~Character()
{
	std::cout << "Destructor Character." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->slots[i];
		this->slots[i] = NULL;
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		 for (int i = 0; i < 4; i++) 
        	if (this->slots[i] == m)
            	return ;
		for (int i = 0; i < 4; i++)
		{
			if (!this->slots[i])
			{
				this->slots[i] = m;
				return ;
			}	
		}
	}
	std::cout << "Einventory Is Full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 4 && this->slots[idx])
	{
		delete this->slots[idx];
		this->slots[idx] = NULL;
		return ;
	}
	std::cout << "Materia Doesn't Exist." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 4 && this->slots[idx])
		this->slots[idx]->use(target);
	else
	std::cout << "Materia Doesn't Exist." << std::endl;
}