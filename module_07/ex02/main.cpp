/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:34:58 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/21 13:11:46 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void ) 
{
     Array<int> numbers(5);
    unsigned int size = numbers.size();

    for (unsigned int i = 0; i < size; i++)
    {
        numbers[i] = (i + (i * 2)) / 2;
        std::cout << "array[" << i << "] = " << numbers[i] << std::endl;
    }

    Array<int> otherNumbers = numbers;

    std::cout << "copy --------" << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "array[" << i << "] = " << otherNumbers[i] << std::endl;
    }
    return 0;
}