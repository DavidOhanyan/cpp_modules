/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:51:54 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/23 22:10:19 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP
#define _DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap:public ScavTrap, public FragTrap
{
private:
	std::string _name_;
public:
	DiamondTrap()
	{
		std::cout << "Default DiamondTrap constructor called" << std::endl;
	}
	DiamondTrap(const std::string &name):ScavTrap(name +  "_clap_name"), FragTrap(name +  "_clap_name")
	{
		std::cout << "parametr DiamondTrap constructr called" << std::endl;
		this->_name_ = name;
		this->_Hit_ = FragTrap::_Hit_;
		this->_Energy_ = ScavTrap::_Energy_;
		this->_Attack_ = FragTrap::_Attack_;
	}
	DiamondTrap(const DiamondTrap& other):ClapTrap(other), ScavTrap(other), FragTrap(other)
	{
		std::cout << "Copy DiamondTrap constructor called" << std::endl;
		this->_name_ = other._name_;
		ClapTrap::_name_ = other.ClapTrap::_name_ + "_clap_name";
		// this->_Hit_ = other._Hit_;
		// this->_Energy_ = other._Energy_;
		// this->_Attack_ = other._Attack_;
	}
	DiamondTrap& operator= (const DiamondTrap& other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if(this == &other)
			return(*this);
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		ClapTrap::_name_ = other.ClapTrap::_name_ + "_clap_name";
		this->_name_ = other._name_;
		this->_Hit_ = other._Hit_;
		this->_Energy_ = other._Energy_;
		this->_Attack_ = other._Attack_;
		return(*this);
	}

	// ClapTrap::~ClapTrap()
	// {
	// 	std::cout << "Destructor called" << std::endl;
	// }
};

#endif