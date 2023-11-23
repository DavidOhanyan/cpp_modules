/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:05:47 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/23 17:25:16 by tumolabsstu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WHATEVER_HPP_
#define _WHATEVER_HPP_

#include <iostream>

template <typename T>
void swap(T &t1, T &t2)
{
    T t3 = t1;
    t1 = t2;
    t2 = t3;
}

template <typename T>
T min(const T &t1, const T &t2)
{
    if (t1 < t2)
        return t1;
    return t2;
}

template <typename T>
T max(const T &t1, const T &t2)
{
    if (t1 > t2)
        return t1;
    return t2;
}

#endif
