/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:32:12 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 14:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    try
    {
        Data * dot = new Data;

        dot->data = 11;

        uintptr_t addressValue = Serializer::serialize(dot);
        Data * dotCopy = Serializer::deserialize(addressValue);

        std::cout << "Real dot address: " << dot << std::endl;
        std::cout << "Copy dot address: " << dotCopy << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}