/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:38:05 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/08 20:51:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

void lol(int *a)
{
	std::cout<<"adddres in function = " << a << std::endl;
}

int main()
{	
	int *a = (int *)malloc(sizeof(int));
	std::cout<<"in main address = "<<a<<std::endl;
	lol(a);
	return (0);
}