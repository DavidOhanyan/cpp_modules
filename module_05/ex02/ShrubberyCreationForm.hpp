/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:55 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 10:59:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUBBERYCREATIONFORM_HPP_
#define _SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm: public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& tg);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    static const int MAX_REQUIRED_SIGN = 145;
    static const int MAX_REQUIRED_EXEC = 137;

    void execute(Bureaucrat const & executor) const;
};

#endif