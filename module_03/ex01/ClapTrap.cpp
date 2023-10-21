/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:24:46 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/21 21:47:04 by tumolabsstu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name_("NULL"),_Hit_(0),_Energy_(0),_Attack_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name_(name)
{
	std::cout << "parametr constructr called" << std::endl;
	_Hit_ = 10;
	_Energy_ = 10;
	_Attack_ = 0;
}


ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hit_ && this->_Hit_ >= amount)
	{
		std::cout << "ClapTrap receives " << amount << " Health" << std::endl;
		this->_Hit_ -= amount;
	}
	else
		std::cout << "Dead Cant Be Killed" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hit_)
	{
		if (this->_Energy_)
		{
			std::cout << "ClapTrap Repairsing, " << amount << " Health Points"<<std::endl;
			this->_Hit_ += amount;
			this->_Energy_--;
			return ;
		} 
		std::cout << "Low Energy" << std::endl;
	}
	else
		std::cout << "Dead Cant Repairsing" << std::endl;
}

void ClapTrap::show_info() const
{
	std::cout << "ClapTraps Name " << this->_name_ << std::endl;
	std::cout << "ClapTrap Has " << this->_Hit_ << " Health points" << std::endl;
	std::cout << "ClapTrap Has " << this->_Energy_ << " Energy points" << std::endl;
	std::cout << "ClapTrap Has " << this->_Attack_ << " damage" << std::endl;
}