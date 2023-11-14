/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:23:41 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 19:23:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("unknown"),_signed(false),
    _gradeSign(Bureaucrat::MaxGrade),_gradeExec(Bureaucrat::MinGrade){}

Form:: Form(const std::string& name, const int gradeSign, const int gradeExec):
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    CheckThrow(this->_gradeSign);
    CheckThrow(this->_gradeExec);
}

Form::Form(const Form& other):
    _name(other._name),_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    this->_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

Form::~Form(){}

std::string Form::GetName() const { return this->_name; }

bool Form::GetSigned() const { return this->_signed; }

int Form::GetGradeSign() const { return this->_gradeSign; }

int Form::GetgradeExec() const { return this->_gradeExec; }

void Form::setSigned(bool _signed){ this->_signed = _signed; }

void Form::beSigned(const Bureaucrat& b1)
{
    if (b1.getGrade() <= this->_gradeSign)
        setSigned(true);
    else
        throw GradeTooLowException();
}

void Form::CheckThrow(const int grade) const
{
    if (grade < Bureaucrat::MinGrade)
        throw GradeTooLowException();
    if (grade > Bureaucrat::MaxGrade)
        throw GradeTooHighException();
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!\n");
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!\n");
}


std::ostream& operator << (std::ostream &os, const Form& obj)
{
    os << obj.GetName() << " form state is - signed: " << (obj.GetSigned() ? "yes" : "no")
       << ", required sign grade: "<< obj.GetGradeSign()
        << ", required execute grade: "
        << obj.GetgradeExec();

    return (os);
}