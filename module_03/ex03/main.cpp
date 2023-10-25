/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:49:49 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/24 21:33:12 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    ClapTrap robot_1("rob-bot");
    ClapTrap robot_2;
    ScavTrap *robot_3 = new ScavTrap("vally");
    ClapTrap *ptr = robot_3;

    FragTrap robot_4("FragTrap robot");

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

    // ScavTrap robot
    robot_3->attack("wall");
    delete ptr;

    // FragTrap robot
    robot_4.attack("test test");
    robot_4.highFivesGuys();

    DiamondTrap *diamond_robot = new DiamondTrap("diamond_name_long");


    diamond_robot->show_info();
    delete diamond_robot;

	return (0);	
}