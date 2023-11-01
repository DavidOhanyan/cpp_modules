/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:42:09 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 17:04:20 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp" 

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator = (const Dog &other);
	~Dog();
	void makeSound() const;
};

#endif