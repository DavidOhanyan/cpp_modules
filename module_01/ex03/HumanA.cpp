/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:10:49 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/03 16:12:21 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &obj):h_name(name), wp(&obj)
{}

void HumanA::attack()
{
std::cout << this->h_name << " attacks with their " << wp->getType() << std::endl;
}