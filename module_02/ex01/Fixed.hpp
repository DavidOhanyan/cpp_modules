/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:43:53 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/01 21:44:20 by dohanyan         ###   ########.fr       */
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
	static const int  _fractional_bits_ = 8;
public:
	Fixed();
	Fixed (const int num);
	Fixed (const float num);
	Fixed(const Fixed &other);
	Fixed& operator = (const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt( void ) const;
};

std::ostream& operator << (std::ostream& os, const Fixed &point);
#endif
