/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:39:18 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 16:07:24 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator = (const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const = 0; 
	void setType(const std::string &type);
	std::string getType() const;
};

#endif