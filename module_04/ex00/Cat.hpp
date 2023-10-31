/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:00:50 by dohanyan          #+#    #+#             */
/*   Updated: 2023/10/31 21:02:46 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string &tp);
	Cat(const Cat &other);
	Cat &operator = (const Cat &other);
	~Cat();
	void makeSound() const;
};

#endif