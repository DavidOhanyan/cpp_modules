/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:12:38 by dohanyan          #+#    #+#             */
/*   Updated: 2023/09/05 21:10:22 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	std::string	name; 
	std::string	surname;
	std::string	nickname;
	std::string	secret;
	std::string number;
public:
	void set_name(std::string name);
	void set_surname(std::string surname);
	void set_nickname(std::string nickname);
	void set_secret(std::string secret);
	void set_number(std::string number);

	std::string get_name();
	std::string get_surname();
	std::string get_nickname();
	std::string get_secret();
	std::string get_number(	);
};

#endif 