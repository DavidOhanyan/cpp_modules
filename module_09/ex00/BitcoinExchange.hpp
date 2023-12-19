/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:21 by dohanyan          #+#    #+#             */
/*   Updated: 2023/12/18 20:14:55 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <cstdlib>
#include <deque>

#define ERR_WRONG_ARG "Argument list must contain only input file!"
#define ERR_INVALID_INPUT_FILE "Input file is invalid please make sure that file exist or you have enough permissions"
#define ERR_UNAVAILABLE_DB "DB is unavailable"
#define ERR_INVALID_DB "DB Invalid"
#define ERR_INVALID_IN "Invalid input file"
#define ERR_EMPTY_DB "DB is empty"

#define ERR_BAD_INPUT "Error: bad input => "
#define ERR_NEG_NUM "Error: not a positive number."
#define ERR_LARGE_NUM "Error: too large a number."
#define ERR_OUT_OF_BOUNDS_DATE "date is out of bounds"

class BitcoinExchange
{
private:
	static std::deque<std::string> dq;
	static std::map<std::string, double> map;
	static std::string key;
	static std::string value;
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& );
	BitcoinExchange& operator= (const BitcoinExchange& );
	~BitcoinExchange();
private:
	static void splitString(const std::string& input, char delimiter);
	static void removeSpaces(std::string &str);
	static bool is_all_num(const std::string& str) ;
	static bool isLeapYear( int year );
	static bool validateDbValue();
	static bool validateKey();
	static int validateInValue();
public:
	static void dbFile(std::string fname);
	static void infile(std::string fname);
};

#endif