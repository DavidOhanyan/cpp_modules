/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:04:38 by marvin            #+#    #+#             */
/*   Updated: 2023/11/16 19:04:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
// #include <cmath>

enum literals {CHAR, INT, FLOAT, DOUBLE, NAN, INF};

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator= (const ScalarConverter&);
    ~ScalarConverter();

    static void convert(const std::string& input);

    static void cast_char(const std::string& input);
    static void cast_int(const std::string& input);
    static void cast_float(const std::string& input);
    static void cast_double(const std::string& input)
    ;
    static void print_inf(const std::string& input);
    static void print_nan();
    static void print_char(char ch);
    static void print_int(int val);
    static void print_float(float val, const std::string& input);
    static void print_double(double val, const std::string& input);

    static int finde_type(const std::string input);
};

#endif
