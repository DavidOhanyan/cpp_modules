/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:19:54 by davit2004         #+#    #+#             */
/*   Updated: 2023/09/18 16:24:16 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl h1;

    h1.complain("DEBUG");
    h1.complain("INFO");
    h1.complain("WARNING");
    h1.complain("ERROR");
    return 0;
}