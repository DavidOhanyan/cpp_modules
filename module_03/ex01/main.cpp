/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:49:49 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/23 17:36:45 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot_1("rob-bot");
	ScavTrap robot_2;
    robot_1.show_info();

    robot_1.attack("tree");
    robot_1.attack("enemy");
    robot_1.attack("another enemy");
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.show_info();

    robot_2 = robot_1;
    robot_2.show_info();

	return (0);	
}