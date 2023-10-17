/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:52:45 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/03 17:48:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(),y()
{}

Point::Point(const float fx, const float fy):x(fx),y(fy)
{}

Point::	Point(const Point& other):x(other.x),y(other.y)
{}

Point& Point::operator = (const Point& other)
{
	(void)other;
	return(*this);
}

Point::~Point()
{}
Fixed Point::get_x() const
{
	return(this->x);
}

Fixed Point::get_y() const
{
	return(this->y);
}
