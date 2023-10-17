/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:07:15 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/14 20:44:24 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):h_name(name)
{}

void HumanB::setWeapon(Weapon &club)
{
	wp = &club;
}

void HumanB::attack()
{
	std::cout << this->h_name << " attacks with their " << wp->getType() << std::endl;
}