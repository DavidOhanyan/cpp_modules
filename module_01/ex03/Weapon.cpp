/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:55:23 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/18 22:09:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name):wp_name(name)
{}

const  std::string& Weapon::getType()
{
	return (this->wp_name);
}

void Weapon::setType(std::string name)
{
	this->wp_name = name;
}	