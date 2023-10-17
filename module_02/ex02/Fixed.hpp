/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:43:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/01 21:45:39 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>
#include <fstream>

class Fixed
{
private:
	int _fixed_;
	static const int  _fractional_bits_;
public:
	Fixed();
	Fixed (const int num);
	Fixed (const float num);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed& operator = (const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt( void ) const;
public:
	bool operator >(const Fixed &other) const;
	bool operator >=(const Fixed &other) const;
	bool operator <(const Fixed &other) const;
	bool operator <=(const Fixed &other) const;
	bool operator ==(const Fixed &other) const;
	bool operator !=(const Fixed &other) const;
	Fixed operator +(const Fixed &other) const;
	Fixed operator -(const Fixed &other) const;
	Fixed operator *(const Fixed &other) const;
	Fixed operator /(const Fixed &other) const;
	Fixed& operator ++();
	Fixed operator ++(int);
	Fixed& operator --();
	Fixed operator --(int);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator << (std::ostream& os, const Fixed &point);
#endif
