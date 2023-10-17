/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:12:51 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/10 16:08:18 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook
{
private:
	Contact c1[8];
	bool parse_string(std::string str);
	bool parce_number(std::string str);
	bool space_case(std::string str);
	void make_word(std::string &str, std::string str2);
public:
	void add(int i);
	void search(int count);
};
#endif