/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:39:00 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/23 15:14:58 by dohanyan         ###   ########.fr       */
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
	~ClapTrap();
	ClapTrap& operator= (const ClapTrap& other);
public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void show_info() const;
public:
	void set_name(std::string);
	void set_hit(unsigned int hit);
	void set_energy(unsigned int energy);
	void set_attack(unsigned int attack);
public:
	std::string get_name() const;
	unsigned int get_hit() const;
	unsigned int get_energy() const;
	unsigned int get_attack() const;
public:
	bool enough_health();
	bool enough_energy();
};


#endif