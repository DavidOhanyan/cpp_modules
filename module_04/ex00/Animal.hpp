/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:39:18 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/31 16:16:40 by dohanyan         ###   ########.fr       */
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
	Animal(const std::string &tp);
	Animal(const Animal &other);
	Animal &operator = (const Animal &other);
	virtual ~Animal();
	virtual void setType(const std::string &type);
	virtual void makeSound() const; 
	std::string getType() const;
};

#endif