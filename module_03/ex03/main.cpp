/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:49:49 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/23 22:09:39 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
   
    DiamondTrap obj("dasd");
    DiamondTrap ob2 = obj;
    ob2.show_info();
    // obj.show_info();
    
	return (0);	
}