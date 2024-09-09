/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:22:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:34:08 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name_(name), grade_(grade)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::Bureaucrat(Bureaucrat const & copy) : name_(copy.name_), grade_(copy.grade_)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs) {
		this->grade_ = rhs.grade_;
	}
	return (*this);
}

std::string const Bureaucrat::getName(void) const
{
	return (this->name_);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}


void Bureaucrat::incrementGrade(void)
{
	if (this->grade_ - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->grade_ + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low");
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.executeForm(*this);
		std::cout << this->name_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Failure to execute the form because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

