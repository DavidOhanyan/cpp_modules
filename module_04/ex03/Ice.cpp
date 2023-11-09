/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:31:13 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/09 19:02:17 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("Ice")
{
	std::cout << "Default Ice Constructor." << std::endl;
}

Ice::Ice(std::string const & type):AMateria(type)
{
	std::cout << "Parameter Ice Constructor." << std::endl;
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

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *"<<std::endl;
}