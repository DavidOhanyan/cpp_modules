/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:43:05 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 10:43:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    
private:
    const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;
protected:
     virtual void execute(Bureaucrat const & executor) const = 0;
public:
    AForm();
    AForm(const std::string& name, const int gradeSign, const int gradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

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

    void  executeForm(Bureaucrat const & target) const;

    void checkExec(Bureaucrat const & executor) const;

    void checkSign() const;

    void beSigned(const Bureaucrat& b1);

    void CheckThrow(const int grade) const;
};

std::ostream& operator << (std::ostream &os, const AForm& obj);


#endif