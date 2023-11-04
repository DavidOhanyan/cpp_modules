/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:43:30 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/04 17:59:39 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_

#include <iostream>

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator = (const AMateria &other);
	~AMateria();
	std::string const& getType() const;
	virtual AMateria* clone() const = 0;
	//virtual void use(ICharacter& target);
};

#endif