/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:23:37 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 19:33:34 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{	
	std::cout << "Default WrongCat Constructor" << std::endl;
	this->type = "unknown";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << "Copy WrongCat Constructor" << std::endl;
	this->type = other.type;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	std::cout << "Operator Assignment WrongCat" << std::endl;
	if (this == &other)
		return(*this);
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()	
{
	std::cout << "Destructor WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat makeSound function"<< std::endl;
}
