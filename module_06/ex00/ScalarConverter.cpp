/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:09:45 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 14:09:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &){return (*this);}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& input)
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

void ScalarConverter::cast_char(const std::string& input)
{
    char ch = input[0];
    ScalarConverter::print_char(static_cast<char>(ch));
    ScalarConverter::print_int(static_cast<int>(ch));
    ScalarConverter::print_float(static_cast<float>(ch), input);
    ScalarConverter::print_double(static_cast<double>(ch), input);
}

void ScalarConverter::cast_int(const std::string& input)
{
    int val = std::atoi(input.c_str());
    ScalarConverter::print_char(static_cast<char>(val));
    ScalarConverter::print_int(static_cast<int>(val));
    ScalarConverter::print_float(static_cast<float>(val), input);
    ScalarConverter::print_double(static_cast<double>(val), input);
}

void ScalarConverter::cast_float(const std::string& input)
{
    float val = std::atof(input.c_str());
    ScalarConverter::print_char(static_cast<char>(val));
    ScalarConverter::print_int(static_cast<int>(val));
    ScalarConverter::print_float(static_cast<float>(val), input);
    ScalarConverter::print_double(static_cast<double>(val), input);
}

void ScalarConverter::cast_double(const std::string& input)
{
    double val = std::strtod(input.c_str(), NULL);
    ScalarConverter::print_char(static_cast<char>(val));
    ScalarConverter::print_int(static_cast<int>(val));
    ScalarConverter::print_float(static_cast<float>(val), input);
    ScalarConverter::print_double(static_cast<double>(val), input);
}

void ScalarConverter::print_inf(const std::string& input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << (input[0] == '-' ? "-" : "") << (input[0] == '+' ? "+" : "") << "inff" << std::endl;
    std::cout << "double: " << (input[0] == '-' ? "-" : "") << (input[0] == '+' ? "+" : "") << "inf" << std::endl;
}

void ScalarConverter::print_nan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

void ScalarConverter::print_char(char ch)
{
    if (std::isprint(ch))
        std::cout << "char: " << "'" << ch << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
}

void ScalarConverter::print_int(int val)
{
    std::cout<<"int: "<< val << std::endl;
}

void ScalarConverter::print_float(float val, const std::string& input)
{
    (void)input;
    std::ostringstream strs;
    strs << val;
    std::string input2 = strs.str();
    if(input2.find('.') == std::string::npos && !std::isinf(val))
        std::cout << "float: " << val << ".0f" << std::endl;
    else
        std::cout << "float: " << val << "f" << std::endl;
} 

void ScalarConverter::print_double(double val, const std::string& input)
{
    (void)input;
    std::ostringstream strs;
    strs << val;
    std::string input2 = strs.str();
    // if (input.find('.') != std::string::npos)
    if(input2.find('.') == std::string::npos)
        std::cout << "double: " << val << ".0" << std::endl;
    else
        std::cout << "double: " << val  << std::endl;
}

int ScalarConverter::finde_type(const std::string input)
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
