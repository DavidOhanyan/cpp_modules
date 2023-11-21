/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:08:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 23:08:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

template<typename Container>
void find(const Container& t1, int occurrence)
{
    typename Container::const_iterator it;
    
    it = std::find(t1.begin(), t1.end(), occurrence);
    if (it != t1.end())
        std::cout<<"first occurrence found under index "<< std::distance(t1.begin(), it) << std::endl;
    else
        throw std::runtime_error("occurrence dont found\n");
}


#endif