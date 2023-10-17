/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:00:56 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/01 21:56:18 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed_(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed_ = num * (1 << this->_fractional_bits_);
}

Fixed::Fixed (const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixed_ = roundf(num * (1 << this->_fractional_bits_));
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixed_ = other._fixed_;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this == &other)
		return(*this);
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_ = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixed_ > other._fixed_);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixed_ >= other._fixed_);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixed_ < other._fixed_);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixed_ <= other._fixed_);
}

bool Fixed::operator ==(const Fixed &other) const
{
	return (this->_fixed_ == other._fixed_);
}

bool Fixed::operator !=(const Fixed &other) const
{
	return !(this->_fixed_ == other._fixed_);
}

Fixed Fixed::operator +(const Fixed &other) const
{
	Fixed temp;
	temp._fixed_ = this->_fixed_ + other._fixed_;
	return (temp);
}	

Fixed Fixed::operator -(const Fixed &other) const
{
	Fixed temp;
	temp._fixed_ = this->_fixed_ - other._fixed_;
	return (temp);
}

Fixed Fixed::operator *(const Fixed &other) const
{
	Fixed temp(this->toFloat() * other.toFloat());
	return (temp);
}	

Fixed Fixed::operator /(const Fixed &other) const
{
	Fixed temp(this->_fixed_ / other._fixed_);
	return (temp);
}	

Fixed& Fixed::operator++()
{
	this->_fixed_++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixed_++;
	return(temp);
}

Fixed& Fixed::operator--()
{
	this->_fixed_--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixed_--;
	return(temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return(b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a._fixed_ < b._fixed_)
		return(a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return(b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if(a > b)
		return(a);
	return (b);
}

std::ostream& operator << (std::ostream& os, const Fixed &point)
{
	os << point.toFloat();		
	return os;	
}

const int Fixed::_fractional_bits_ = 8;