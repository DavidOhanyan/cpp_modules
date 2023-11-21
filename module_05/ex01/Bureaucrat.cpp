/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:44 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 13:59:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("unknown"),_grade(MinGrade){}

Bureaucrat::Bureaucrat(const std::string& name, int grade):_name(name),_grade(grade){}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name)
{
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::setGrade(int _grade)
{
	if (_grade < Bureaucrat::MinGrade)
		throw GradeTooLowException();
	if (_grade > Bureaucrat::MaxGrade)
		throw GradeTooHighException();
    this->_grade = _grade;
}

void Bureaucrat::incrementGrade()
{ 
    if (--this->_grade < Bureaucrat::MaxGrade)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (++this->_grade > Bureaucrat::MinGrade)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.GetName() <<" form"<<std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout << this->getName() << " couldn’t sign " << form.GetName() << " form because " << ex.what() << std::endl;
	}
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!\n");
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!\n");
}

std::ostream& operator << (std::ostream &os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}

const int Bureaucrat::MinGrade = 1;
const int Bureaucrat::MaxGrade = 150;