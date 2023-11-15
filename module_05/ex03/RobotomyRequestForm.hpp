/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:54:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 12:54:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class AForm;

class RobotomyRequestForm: public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& tg);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    static const int MAX_REQUIRED_SIGN = 72;
    static const int MAX_REQUIRED_EXEC = 45;

    void execute(Bureaucrat const & executor) const;
};


#endif