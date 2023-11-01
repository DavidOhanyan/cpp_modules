/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:17 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 20:37:18 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *meta = new Animal[10];
    // for (int i = 0; i < 5; i++)
    //     meta[i] = new Cat();
    // for (int i = 5; i < 10; i++)
    //     meta[i] = new Dog();
    meta[0] = new Dog();
	return (0);
}