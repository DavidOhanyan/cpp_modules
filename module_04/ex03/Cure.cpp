/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:27:51 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/06 18:28:17 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("Cure")
{
	std::cout << "Default Cure Constructor." << std::endl;
}

Cure::Cure(std::string const & type):AMateria(type)
{
	std::cout << "Parameter Cure Constructor." << std::endl;
}

Cure::Cure(const Cure &other):AMateria(other)
{
	std::cout << "Copy Cure Constructor." << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Operator Assignment Cure." << std::endl;
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor Cure." << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}