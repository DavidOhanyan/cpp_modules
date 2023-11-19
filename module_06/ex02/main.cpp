/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:09:17 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 17:09:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base* someRandomPtr = generate();

    std::cout << "----------Random---------" << std::endl;
    identify(someRandomPtr);
    identify(*someRandomPtr);
    delete someRandomPtr;
    {
        Base* a = new A();
        std::cout << "------------A------------" << std::endl;
        identify(a);
        identify(*a);
        delete a;
    }
    {
        Base* b = new B();
        std::cout << "------------B------------" << std::endl;
        identify(b);
        identify(*b);
        delete b;
    }
    {
        Base* c = new C();
        std::cout << "------------C------------" << std::endl;
        identify(c);
        identify(*c);
        delete c;
    }
    return (0);
}
