/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:51:54 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/24 17:33:49 by dohanyan         ###   ########.fr       */
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
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();
public:
	DiamondTrap& operator= (const DiamondTrap& other);
	using ScavTrap::attack;
	void whoAmI();
};

#endif