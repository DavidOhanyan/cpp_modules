/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:33:08 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 22:33:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>

template<typename T>
class Array
{
private:
    size_t len;
    T* array;
public:
    Array():len(0),array(NULL)
    {}
    Array(unsigned int n)
    {
        this->len = n;
        this->array = new T[n];
        for (size_t i = 0; i < len; i++)
            this->array[i] = T();
    }
    Array(const Array<T>& other):array(NULL)
    {
        this->len = other.len;
        this->array = new T[this->len];
        for (size_t i = 0; i < this->len; i++)
            this->array[i] = other.array[i];
    }
    Array<T>& operator= (const Array<T>& other)
    {
        if (this != &other)
        {
            if (this->array)
            {
                delete [] this->array;
                this->array = NULL;
            }
            this->len = other.len;

            this->array = new T[this->len];
            for (size_t i = 0; i < this->len; i++)
                this->array[i] = other.array[i];
        }
        return (*this);
    }
    ~Array()
    {
        if (this->array)
            delete []this->array;
    }
    T& operator[](size_t index)
    {
        if (index >= this->size())
            throw std::out_of_range("index is out of range!");
        return (this->array[index]);
    }
    const T& operator[](size_t index) const
    {
        if (index >= this->size())
            throw std::out_of_range("index is out of range!");
        return (this->array[index]);
    }
    size_t size() const
    {
        return (this->len);
    }
};

#endif