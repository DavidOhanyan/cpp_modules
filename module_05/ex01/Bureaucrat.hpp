/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:21:40 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 22:21:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator= (const Bureaucrat& other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void setGrade(int _grade);

	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form) const;

	class GradeTooLowException: public std::exception
	{
	public:
		 const char *what() const throw();
	};

	class GradeTooHighException: public std::exception
	{	   
	public:
		const char *what() const throw();
	};


	static const int MinGrade;
	static const int MaxGrade;
};

std::ostream& operator << (std::ostream &os, const Bureaucrat& obj);

#endif