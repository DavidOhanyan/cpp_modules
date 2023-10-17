/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:36:05 by davit2004         #+#    #+#             */
/*   Updated: 2023/09/18 16:23:17 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string arr[] = {"DEBUG","INFO","WARNING","ERROR","NULL"};
    int i = 0;
    void(Harl::*fptr[])(void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    while (level != arr[i] && arr[i] != "NULL")
        i++;
    switch (i)
    {
        case(4):
        {
            std::cout<<"ERROR"<<std::endl;
            exit(1);
        }
    }
    (this->*fptr[i])();
}