/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:05:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 08:39:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name_("No name"), isSigned_(false), gradeToSign_(1), gradeToExecute_(1)
{
	std::cout << "private method" << std::endl;
}

Form::Form(const std::string & name, int gradeToSign) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(0)
{
	if (gradeToSign < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string & name, int gradeToSign, int gradeToExecute) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form & src) : name_(src.name_), isSigned_(false), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_)
{
	
}

Form::~Form(void)
{
	return ;
}

Form& Form::operator=(const Form & rhs)
{
	if (this != &rhs)
		this->isSigned_ = rhs.isSigned_;
	return (*this);
}

std::string const Form::getName(void) const
{
	return(this->name_);
}

bool Form::getSigned(void) const
{
	return (this->isSigned_);
}

int	Form::getGradeToSign(void) const
{
	return (this->gradeToSign_);
}

int	Form::getgradeToExecute(void) const
{
	return (this->gradeToExecute_);
}

void Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (this->isSigned_)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	this->isSigned_ = true;
}

std::ostream & operator<<(std::ostream & o, const Form & rhs)
{
	o << "Form name: " << rhs.getName() << ", Grade to sign: " << rhs.getGradeToSign() << ", Grade to exec: " << rhs.getgradeToExecute() << std::endl;
	o << "and is the form is " << (rhs.getSigned() ? "signed" : "not yet signed") << std::endl;
	return (o);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char * Form::AlreadySignedException::what() const throw()
{
	return ("Error: Form already signed");
}
