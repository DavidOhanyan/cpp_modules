/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:26:57 by tumolabsstu       #+#    #+#             */
/*   Updated: 2023/10/23 18:55:59 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap:virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string const &name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
public:
    ScavTrap& operator= (const ScavTrap& other);
    void attack(const std::string& target);
    void guardGate();
};

#endif