/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:00:20 by marvin            #+#    #+#             */
/*   Updated: 2023/11/16 12:00:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.hpp"

bool correct_input(std::string input, size_t input_size)
{
	bool dot = false;
	bool end_f = false;
	bool sign = false;
	size_t i = 0;

	if (input == "nan" || input == "nanf"
		|| input == "inf" || input == "-inf" || input == "+inf"
		||	input == "inff" || input == "-inff" || input == "+inff")
		return (true);
	if(input[0] == '-' || input[0] == '+')
	{
		input = input.substr(1);
		input_size--;
		sign = true;
	}
	if (!std::isdigit(input[0]) && input.size() == 1 && !sign)
		return (true);
	for (; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			if((input[i] == '.' && std::isdigit(input[i + 1]) && i != 0 && !dot ))
				dot = true;
			else
				if (input[i] == 'f' && dot && input[input_size - 1] == 'f' && !end_f)
					end_f = true;
			else
				break;
		}
	}
	if (i == input.size())
		return (true);
	return (false);
}

void validator(int argc, char **argv)
{
    if (argc != 2)
        throw std::runtime_error("1bad argument!");

    std::string input = argv[1];
    size_t input_size = input.length();

    if (!input_size)
         throw std::runtime_error("2bad argument!");
    
    if (!correct_input(input, input_size))
        throw std::runtime_error("3bad argument! validic");

}