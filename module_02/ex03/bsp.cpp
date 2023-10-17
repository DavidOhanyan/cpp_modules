/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:20:57 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/03 17:21:06 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed module(Fixed num)
{
	if (num < 0)
		return(num * -1);
	return(num);
}

Fixed area(Point const a, Point const b, Point const c)
{
	return (((a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y())) / 2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	Fixed ABC = module(area(a, b, c));
	Fixed PAB = module(area(point, a, b));
	Fixed PBC = module(area(point, b, c));
	Fixed PCA = module(area(point, c, a));
	
	return(ABC == (PAB + PBC + PCA));
}