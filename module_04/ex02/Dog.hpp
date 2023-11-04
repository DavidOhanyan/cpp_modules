/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:42:09 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 16:01:46 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp" 
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator = (const Dog &other);
	~Dog();
	void makeSound() const;
};

#endif