/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:00:25 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 14:00:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRESIDENTIALPARDONFORM_HPP
#define _PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& tg);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator= (const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    static const int MAX_REQUIRED_SIGN = 25;
    static const int MAX_REQUIRED_EXEC = 5;

    void execute(Bureaucrat const & executor) const;
};


#endif