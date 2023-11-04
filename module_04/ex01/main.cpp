/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:17 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 15:58:40 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal **meta = new Animal*[100];
    for (int i = 0; i < 50; i++)
        meta[i] = new Cat();
    for (int i = 50; i < 100; i++)
        meta[i] = new Dog();
    for (int i = 0; i < 100; i++)
    {
        meta[i]->makeSound();
        delete meta[i];
    }
    delete [] meta;
	return (0);
}