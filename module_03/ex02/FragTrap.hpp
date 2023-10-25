/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:42:09 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/25 18:28:42 by dohanyan         ###   ########.fr       */
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
	~FragTrap();
public:
	void highFivesGuys(void);
};

#endif