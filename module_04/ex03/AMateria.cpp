/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:53:31 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/09 18:57:50 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default AMateria Constructor." << std::endl;
	this->type = "unknown";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "Parameter AMateria Constructor." << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy AMateria Constructor." << std::endl;
	this->type = other.type;
}

AMateria &AMateria::operator = (const AMateria &other)
{
	std::cout << "Operator Assignment AMateria." << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria." << std::endl;
}

std::string const& AMateria::getType() const
{
	std::cout << "GetType AMateria Function." << std::endl;
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "I'm a Simple Materia" << target.getName() << std::endl;
}