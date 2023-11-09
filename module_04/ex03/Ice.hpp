/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:11:14 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/09 19:01:30 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &other);
	Ice &operator = (const Ice &other);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif