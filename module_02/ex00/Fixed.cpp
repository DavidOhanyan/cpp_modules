/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:34:39 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/05 16:15:22 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits_ = 8;

Fixed::Fixed():_fixed_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_ = other.getRawBits();
}

Fixed & Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_ = other.getRawBits();

	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor  " << std::endl;
}

int Fixed:: getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_ = raw;
}
