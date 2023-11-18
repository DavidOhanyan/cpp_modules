/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:58:42 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 14:58:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include <iostream>
#include <stdint.h>

struct Data
{
    int data;
};

class Serializer
{
public:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif