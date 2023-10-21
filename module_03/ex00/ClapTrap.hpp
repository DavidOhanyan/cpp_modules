/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:39:00 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/21 21:57:05 by tumolabsstu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name_;
	unsigned int _Hit_;
	unsigned int _Energy_;
	unsigned int _Attack_;
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator= (const ClapTrap& other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void show_info() const;
};

#endif