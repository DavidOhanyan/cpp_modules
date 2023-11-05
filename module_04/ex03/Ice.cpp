/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:31:13 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/05 19:10:53 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("Ice")
{
	std::cout << "Default AMateria Constructor." << std::endl;
}

Ice::Ice(std::string const & type):AMateria(type)
{
	std::cout << "Parameter AMateria Constructor." << std::endl;
}

Ice::Ice(const Ice &other):AMateria(other)
{
	std::cout << "Copy Ice Constructor." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Operator Assignment Ice." << std::endl;
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor Ice." << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}