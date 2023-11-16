/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:57:19 by marvin            #+#    #+#             */
/*   Updated: 2023/11/16 11:57:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VALIDATOR_HPP_
#define _VALIDATOR_HPP_

#include <iostream>
#include <string>

void validator(int argc, char **argv);
bool correct_input(std::string input, size_t input_size);
#endif