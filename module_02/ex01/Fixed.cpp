/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:00:56 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/14 22:52:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_ = num * (1 << this->_fractional_bits_);
}

Fixed::Fixed (const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_ = roundf(num * (1 << this->_fractional_bits_));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_ = other._fixed_;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this == &other)
		return(*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_ = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed:: getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_ = raw;
}


float Fixed::toFloat(void) const
{
	float to_f = static_cast<float>(this->_fixed_);
	return (to_f / (1 << this->_fractional_bits_));	
}

int Fixed::toInt( void ) const
{
	int to_i = static_cast<int>(this->_fixed_);
	return (to_i / (1 << this->_fractional_bits_));
}

std::ostream& operator << (std::ostream& os, const Fixed &point)
{
	os << point.toFloat();		
	return os;	
}