/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:42:06 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/24 17:43:08 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;	
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "parametr FragTrap constructr called" << std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 100;
	this->_Attack_ = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy FragTrap assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;	
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "high fives all form " << this->_name_ << " to all classes :)" <<std::endl;
}