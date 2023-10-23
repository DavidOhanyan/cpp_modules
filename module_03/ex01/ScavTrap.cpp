/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:45:34 by tumolabsstu       #+#    #+#             */
/*   Updated: 2023/10/22 18:38:32 by tumolabsstu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default child constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "ScavTrap parametr constructor called"<< std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 50;
	this->_Attack_ = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy chhild assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
     std::cout<< "chhild Attack function called" << std::endl;
    if(this->_Hit_)
	{
		if (this->_Energy_)
		{
		    std::cout << "ClapTrap " <<this->_name_; 
		    std::cout << " attacks " << target;
			std::cout << " , causing " << this->_Attack_ << " points of damage!" << std::endl;
			this->_Energy_--;
			return ;
		}
		std::cout << "Low Energy"<<std::endl;
		return ;
	}
	std::cout << "Dead Cant Attack" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor chhild called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name_ << " in Gate keeper mode." << std::endl;
}