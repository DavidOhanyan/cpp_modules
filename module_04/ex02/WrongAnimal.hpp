/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:13:15 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/01 17:07:14 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGANIMAL_HPP_
#define _WRONGANIMAL_HPP_

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator = (const WrongAnimal &other);
	virtual ~WrongAnimal();
	void makeSound() const; 
	void setType(const std::string &type);
	std::string getType() const;
};

#endif