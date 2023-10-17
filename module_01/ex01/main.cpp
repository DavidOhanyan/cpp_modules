/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:32:23 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/13 20:46:18 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *z1 = NULL;

	z1 = zombieHorde(N, "Samson");
	// for(int i = 0; i < N; i++)
	// 	z1[i].announce();
	delete[] z1;
	return (0);
}
