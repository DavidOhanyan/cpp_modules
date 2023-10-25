/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:45:34 by tumolabsstu       #+#    #+#             */
/*   Updated: 2023/10/24 21:26:40 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "parametr ScavTrap constructor called"<< std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 50;
	this->_Attack_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy ScavTrap assignment operator called" << std::endl;
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy chhild assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrav attack function" << std::endl;
	if (enough_health() && enough_energy())
	{
		std::cout << "ScavTrap " <<this->_name_; 
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_Attack_ << " points of damage!" << std::endl;
		this->_Energy_--;
		return ;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name_ << " in Gate keeper mode." << std::endl;
}