/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:07:13 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/24 17:15:24 by tumolabsstu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template <typename T>
void printValue(const T& value) {
    std::cout << value << " ";
}

// template<typename T, typename Func>
// void iter(T *t1, size_t len, Func func)
// {
//     for (size_t i = 0; i < len; i++)
//         func(t1[i]);
// }

template<typename T>
void iter(T *t1, size_t len, void(*func)(const T&))
{
    for (size_t i = 0; i < len; i++)
        func(t1[i]);
}

template<typename T>
void iter(const T *t1, size_t len, void(*func)(const T&))
{
    for (size_t i = 0; i < len; i++)
        func(t1[i]);
}

#endif