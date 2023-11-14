/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:20:28 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/14 22:53:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_

#include <iostream>

class Brain
{
private:
	std::string ideas [100];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator = (const Brain &other);
	~Brain();
	void setIdea(const std::string &idea, const int &index);
	std::string getIdea(const int &index) const;
};

#endif