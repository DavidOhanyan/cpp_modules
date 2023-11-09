/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:11:40 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/09 19:02:43 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria *slots[4];
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator =(const Character &other);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
