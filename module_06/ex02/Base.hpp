/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:09:51 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 17:09:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
public:
    virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif