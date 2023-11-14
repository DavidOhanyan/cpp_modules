/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:23:38 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 19:23:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FORM_HPP_
#define _FORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;
public:
    Form();
    Form(const std::string& name, const int gradeSign, const int gradeExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string GetName() const;
    bool GetSigned () const;
    int GetGradeSign() const;
    int GetgradeExec() const;

    void setSigned(bool _signed);

    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    void beSigned(const Bureaucrat& b1);

    void CheckThrow(const int grade) const;
};

std::ostream& operator << (std::ostream &os, const Form& obj);


#endif