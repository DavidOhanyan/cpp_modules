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

    static void convert(const std::string& input)
    {
        int type = finde_type(input);
        if (type == INF)
            ScalarConverter::print_inf(input);
        if (type == NAN)
            ScalarConverter::print_nan();
        if (type == CHAR)
            ScalarConverter::cast_char(input);
        if (type == INT)
            ScalarConverter::cast_int(input);
        if (type == FLOAT)
            ScalarConverter::cast_float(input);
        if (type == DOUBLE)
            ScalarConverter::cast_double(input);
    }

    static void print_inf(const std::string& input)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (input[0] == '-' ? "-" : "") << (input[0] == '+' ? "+" : "") << "inff" << std::endl;
        std::cout << "double: " << (input[0] == '-' ? "-" : "") << (input[0] == '+' ? "+" : "") << "inf" << std::endl;
    }

    static void print_nan()
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }

    static void print_char(char ch)
    {
        if(std::isprint(ch))
            std::cout << "char: " << "'" << ch << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
    }

    static void print_int(int val)
    {
        std::cout<<"int: "<< val << std::endl;
    }

    static void print_float(float val, const std::string& input)
    {
        size_t ch = input.find('.');
        if (ch == std::string::npos || (ch != std::string::npos && input[ch + 1] == '0'))
            std::cout << "float: " << val << ".0f" << std::endl;
        else
            std::cout << "float: " << val << "f" << std::endl;
    }

    static void print_double(double val, const std::string& input)
    {
        if (input.find('.') != std::string::npos)
            std::cout << "double: " << val  << std::endl;
        else
            std::cout << "double: " << val << ".0" << std::endl;
    }

    static void cast_char(const std::string& input)
    {
         char ch = input[0];
         ScalarConverter::print_char(static_cast<char>(ch));
         ScalarConverter::print_int(static_cast<int>(ch));
         ScalarConverter::print_float(static_cast<float>(ch), input);
         ScalarConverter::print_double(static_cast<double>(ch), input);
    }

    static void cast_int(const std::string& input)
    {
        // (void)input;
        int val = std::atoi(input.c_str());
        ScalarConverter::print_char(static_cast<char>(val));
        ScalarConverter::print_int(static_cast<int>(val));
        ScalarConverter::print_float(static_cast<float>(val), input);
        ScalarConverter::print_double(static_cast<double>(val), input);
    }

    static void cast_float(const std::string& input)
    {
        float val = std::atof(input.c_str());
        ScalarConverter::print_char(static_cast<char>(val));
        ScalarConverter::print_int(static_cast<int>(val));
        ScalarConverter::print_float(static_cast<float>(val), input);
        ScalarConverter::print_double(static_cast<double>(val), input);
    }

    static void cast_double(const std::string& input)
    {
        double val = std::strtod(input.c_str(), NULL);
        ScalarConverter::print_char(static_cast<char>(val));
        ScalarConverter::print_int(static_cast<int>(val));
        ScalarConverter::print_float(static_cast<float>(val), input);
        ScalarConverter::print_double(static_cast<double>(val), input);
    }

    static int finde_type(const std::string input)
    {
        if (input == "inf" || input == "-inf" || input == "+inf"
		||	input == "inff" || input == "-inff" || input == "+inff")
		return (INF);
        if (input == "nan" || input == "nanf")
            return (NAN);

        if (!std::isdigit(input[0]) && input.size() == 1)
            return (CHAR);
        
        bool dot = input.find('.') != std::string::npos;
        bool chf = input.find('f') != std::string::npos;

        if (input.size() <= 11 && !dot && !chf)
        {
            long val = std::atol(input.c_str());
            if (val >= INT_MAX && val <= INT_MAX)
            return (INT);
        }

        if (dot && chf)
            return (FLOAT);
        
        return (DOUBLE);
    }
};

#endif