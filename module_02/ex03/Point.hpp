/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:17:10 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/03 17:48:59 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
 	Point();
	Point(const float fx, const float fy);
	Point(const Point& other);
	Point& operator = (const Point& other);
	~Point();
	Fixed get_x() const;
	Fixed get_y() const;
};

Fixed module(Fixed num);
Fixed area(Point const a, Point const b, Point const c);
bool bsp(Point const a, Point const b, Point const c, Point const point);