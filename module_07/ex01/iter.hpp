/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:07:13 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/20 18:16:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template<typename T>
void iter(T *t1, size_t len, void(*func)(T&))
{
    for (size_t i = 0; i < len; i++)
        func(t1[i]);
}

#endif