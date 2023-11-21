/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:25 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/20 18:22:07 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void template_func(T& param1)
{
    param1 += param1;
}

void ordinary_func(int &a)
{
    a += 100000000;
}

int main()
{
    int a[] = {1, 2, 3,4 ,5 };
    std::string b[] = {"asd", "asdasd", "asdasd", "asdasd", "asdasd"};

    iter(a, 5, ordinary_func);
    iter(b, 5, template_func);
    
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << b[i] << " ";
    }

    std::cout << std::endl;
    

    return (0);
}