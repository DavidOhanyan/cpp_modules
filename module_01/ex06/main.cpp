/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:19:54 by davit2004         #+#    #+#             */
/*   Updated: 2023/09/19 17:14:31 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h1;
    if (argc !=  2)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }
    h1.complain(argv[1]);
    return 0;
}