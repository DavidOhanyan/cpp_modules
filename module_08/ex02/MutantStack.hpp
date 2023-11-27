/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:14:52 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 00:14:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template<class Tp, class Container = std::deque<Tp> >
class MutantStack:public std::stack<Tp, Container>
{
public:
    MutantStack(){}
    MutantStack(const MutantStack<Tp, Container>& other):std::stack<Tp, Container>(other){}
    MutantStack& operator=(const MutantStack<Tp, Container>& other){if (this != &other){std::stack<Tp, Container>::operator=(other);} return (*this);}
    ~MutantStack(){}

    typedef typename std::stack<Tp, Container>::container_type::iterator iterator;
    typedef typename std::stack<Tp, Container>::container_type::const_iterator const_iterator;
    typedef typename std::stack<Tp, Container>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<Tp, Container>::container_type::const_reverse_iterator const_reverse_iterator;


    iterator begin(){return (this->c.begin());}
    iterator end(){return (this->c.end());}

    const_iterator cbegin(){return (this->c.cbegin());}
    const_iterator cend(){return (this->c.cend());}

    reverse_iterator rbegin(){return (this->c.rbegin());}
    reverse_iterator rend(){return (this->c.rend());}

    const_reverse_iterator crbegin(){return (this->c.crbegin);}
    const_reverse_iterator crend(){return (this->c.crend);}
};

#endif