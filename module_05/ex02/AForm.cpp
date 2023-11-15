/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:43:14 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 10:43:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("unknown"),_signed(false),
    _gradeSign(Bureaucrat::MaxGrade),_gradeExec(Bureaucrat::MinGrade){}

AForm:: AForm(const std::string& name, const int gradeSign, const int gradeExec):
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    CheckThrow(this->_gradeSign);
    CheckThrow(this->_gradeExec);
}

AForm::AForm(const AForm& other):
    _name(other._name),_gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    this->_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

AForm::~AForm(){}

std::string AForm::GetName() const { return this->_name; }

bool AForm::GetSigned() const { return this->_signed; }

int AForm::GetGradeSign() const { return this->_gradeSign; }

int AForm::GetgradeExec() const { return this->_gradeExec; }

void AForm::setSigned(bool _signed){ this->_signed = _signed; }

void AForm::executeForm(Bureaucrat const & target) const
{
    this->execute(target);
}

void AForm::beSigned(const Bureaucrat& b1)
{
    if (b1.getGrade() <= this->_gradeSign)
        setSigned(true);
    else
        throw GradeTooLowException();
}

void AForm::CheckThrow(const int grade) const
{
    if (grade < Bureaucrat::MinGrade)
        throw GradeTooLowException();
    if (grade > Bureaucrat::MaxGrade)
        throw GradeTooHighException();
}


void AForm::checkExec(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->_gradeExec)
        throw GradeTooLowException();
}

void AForm::checkSign() const
{
    if (!this->GetSigned())
        throw std::runtime_error("Form cannot be signed\n"); 
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!\n");
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!\n");
}


std::ostream& operator << (std::ostream &os, const AForm& obj)
{
    os << obj.GetName() << " form state is - signed: " << (obj.GetSigned() ? "yes" : "no")
       << ", required sign grade: "<< obj.GetGradeSign()
        << ", required execute grade: "
        << obj.GetgradeExec();

    return (os);
}