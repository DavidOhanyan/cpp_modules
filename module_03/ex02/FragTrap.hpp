/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:42:09 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/23 17:41:34 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap& other);
	virtual ~FragTrap();
public:
	void highFivesGuys(void);
};

#endif