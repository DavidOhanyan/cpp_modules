/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:04:51 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 23:04:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try
    {
        int arr[] = {11, 22, 33, 44, 55, 66, 77};
        std::vector<int> v1(arr, arr + 7);
        find(v1, 55);
        // find(v1, 67);//error case
    }
    catch(const std::runtime_error &error)
    {
        std::cout << "Error:" << std::endl;
        std::cout << error.what();
    }
    return (0);
}