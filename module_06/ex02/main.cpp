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

class Glxavor
{
public:
    virtual ~Glxavor(){}

};

class Axjik:public Glxavor
{};

class Txa:public Glxavor
{};

int main()
{
    Base &b1 = *generate();
    identify(b1);
    // Txa t1,t2;
    // Axjik a1;

    // Glxavor& g1 = a1;
    // t1 = dynamic_cast<Txa&>(g1);
    
    // Glxavor* g1 = new Axjik();
    // Txa *t1;
    // Axjik *a1;

    // t1 = dynamic_cast<Txa*>(g1);
    // if(t1)
    //     std::cout<<"toshnia\n";
    // else
    //     std::cout<<"voria\n";
    // try
    // {
    // Axjik a1;
    // Axjik a2;
    // Txa t1;

    // Glxavor& g1 = a1;
    // t1 = dynamic_cast<Axjik&>(g1);
    // }
    // catch(const std::exception& ex)
    // {
    //     std::cout<<ex.what()<<std::endl;
    // }
    // txa t1;

    // axjik *ax = dynamic_cast<axjik*>(t);
    // if (ax)
    //     std::cout<<"tosnia\n";
    // else
    //     std::cout<<"voria\n";

    // delete t;
    // txa*p = new axjik();
    // Base *b1 = generate();
    // identify(b1);
    // Base &b1 = *generate();
    // identify(b1);
    return (0);
}
