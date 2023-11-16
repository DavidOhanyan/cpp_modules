/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:47:20 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 23:47:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    try
    {
        validator(argc, argv);
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return (0);
}