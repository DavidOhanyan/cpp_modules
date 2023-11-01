/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:17 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 17:14:23 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " is cat type" << std::endl;
    std::cout << cat->getType() << " is dog type" << std::endl;

    dog->makeSound(); //will output the cat sound!
    cat->makeSound();
        
    meta->makeSound();

    std::cout << "------------- Wrong animals below" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongDog = new WrongCat();
    std::cout << wrongDog->getType() << " is dog type" << std::endl;

    wrongDog->makeSound();

    wrongMeta->makeSound();

    std::cout << "----------------------------------" << std::endl;

    delete meta;
    delete dog;
    delete cat;

    delete wrongMeta;
    delete wrongDog;
	return (0);
}