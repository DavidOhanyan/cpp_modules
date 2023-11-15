/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:20:13 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 22:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
	try 
    {
        const Bureaucrat John("John", 12);
        Intern someRandomIntern;
        AForm* rrf = NULL;
        std::cout<<John<<std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout<<*rrf<<std::endl;
        rrf->beSigned(John);
        delete rrf;
    }
    catch(std::exception & exc) 
    {
        std::cout << exc.what();
    }

   
	return (0);
}