/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabsstudent <tumolabsstudent@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:34:58 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/24 20:42:44 by tumolabsstu      ###   ########.fr       */
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

    // const Array<int> arr(MAX_VAL);
    // std::cout << "array[5] = " << arr[5] << std::endl;
    return 0;
}
