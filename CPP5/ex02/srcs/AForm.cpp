/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:05:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 11:50:21 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): name_("No name"), isSigned_(false), gradeToSign_(1), gradeToExecute_(1)
{
	std::cout << "private method" << std::endl;
}

AForm::AForm(const std::string & name, int gradeToSign) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(0)
{
	if (gradeToSign < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string & name, int gradeToSign, int gradeToExecute) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & src) : name_(src.name_), isSigned_(false), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_)
{
	
}

AForm::~AForm(void)
{
	return ;
}

AForm& AForm::operator=(const AForm & rhs)
{
	if (this != &rhs)
		this->isSigned_ = rhs.isSigned_;
	return (*this);
}

std::string const AForm::getName(void) const
{
	return(this->name_);
}

bool AForm::getSigned(void) const
{
	return (this->isSigned_);
}

int	AForm::getGradeToSign(void) const
{
	return (this->gradeToSign_);
}

int	AForm::getgradeToExecute(void) const
{
	return (this->gradeToExecute_);
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (this->isSigned_)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	this->isSigned_ = true;
}

void	AForm::executeForm(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->gradeToExecute_)
		throw AForm::GradeTooLowException();
	else if (!this->isSigned_)
		throw AForm::NotYetSignedException();
	else
		this->beExecuted();
}

std::ostream & operator<<(std::ostream & o, const AForm & rhs)
{
	o << "Form name: " << rhs.getName() << ", Grade to sign: " << rhs.getGradeToSign() << ", Grade to exec: " << rhs.getgradeToExecute() << std::endl;
	o << "and is the form is " << (rhs.getSigned() ? "signed" : "not yet signed") << std::endl;
	return (o);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char * AForm::AlreadySignedException::what() const throw()
{
	return ("Error: Form already signed");
}

const char * AForm::NotYetSignedException::what() const throw()
{
	return ("Error: Form is not yet signed");
}
