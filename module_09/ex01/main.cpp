/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:59 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/07 18:27:17 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

int main()
{
	std::stack<double> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	std::cout << s1.top() << std::endl;
	s1.pop();
	std::cout << s1.top() << std::endl;
 	return (0);
}