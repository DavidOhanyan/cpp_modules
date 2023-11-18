/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:10:49 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 17:10:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base *generate()
{
    std::srand(time(NULL));
    Base*objs[3] = {new A(), new B(), new C()};
    int i = rand() % 3;
    int j = 0;
    while (j < 3)
    {
        if (j != i)
            delete objs[j];
        j++;
    }
    
    return (objs[i]);
    // return (new A());
}

// void identify(Base* p)
// {
//     A *a1 = dynamic_cast<A*>(p);
//     B *a2 = dynamic_cast<B*>(p);
//     C *a3 = dynamic_cast<C*>(p);

//     if(a1)
//         std::cout << "A" << std::endl;
//     if(a2)
//         std::cout << "B" << std::endl;
//     if(a3)
//         std::cout << "C" << std::endl;
//     delete p;
// }

void identify(Base& p)
{ 
    try
    {
        A a1;
        a1 = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(...)
    {
        // std::cout<<"dsad\n";
    }
    try
    {
        B b1;
        b1 = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(...)
    {
        // std::cout<<"dsad\n";
    }
    try
    {
        C c1;
        c1 = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(...)
    {
        // std::cout<<"dsad\n";
    }

}