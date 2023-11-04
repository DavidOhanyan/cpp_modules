/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:31:13 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 22:26:39 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Default AMateria Constructor" << std::endl;
}

Ice::Ice(std::string const & type):AMateria(type)
{
	std::cout << "Parameter AMateria Constructor" << std::endl;
}

Ice::Ice(const Ice &other):
{
	std::cout << "Copy Ice Constructor" << std::endl;
	this->type = other.type;
}