/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:27:16 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/06 18:27:30 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(std::string const & type);
	Cure(const Cure &other);
	Cure &operator = (const Cure &other);
	~Cure();
	AMateria* clone() const;
	// void use(ICharacter& target);
};

#endif