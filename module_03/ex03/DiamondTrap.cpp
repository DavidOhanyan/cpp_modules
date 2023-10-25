/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:57:02 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/24 21:31:22 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::	DiamondTrap(const std::string &name): ClapTrap(name +  "_clap_name"),ScavTrap(name +  "_clap_name"),
	FragTrap(name +  "_clap_name"),_name_(name)
{
	std::cout << "parametr DiamondTrap constructr called" << std::endl;
	this->_Hit_ = 100;//FragTrap Hit points
	this->_Energy_ = 50;//ScavTrap energy point
	this->_Attack_ = 30;//Attack Hit points
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	std::cout << "Copy DiamondTrap assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	ClapTrap::_name_ = other.ClapTrap::_name_ + "_clap_name";
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
	return(*this);
}

DiamondTrap ::~DiamondTrap()
{
	std::cout << "Destructor DiamondTrap called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout<< "I am "<<this->_name_<<std::endl;
	std::cout<<"ClapTrap name is "<< ClapTrap::_name_<<std::endl;
}