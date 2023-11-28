/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:21 by dohanyan          #+#    #+#             */
/*   Updated: 2023/11/28 21:44:43 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <vector>
#include <map>

class BitcoinExchange
{
private:
	std::vector<std::string> vec;
	std::map<std::string, double> map;
private:
	BitcoinExchange(){}
	BitcoinExchange(const BitcoinExchange& other){this->vec = other.vec; this->map = other.map;}
	BitcoinExchange& operator= (const BitcoinExchange& other){if (this != &other){this->vec = other.vec; this->map = other.map;}return (*this);}
	~BitcoinExchange(){}
};

#endif