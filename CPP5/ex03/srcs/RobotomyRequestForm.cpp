/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:01:16 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:53:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target_("Unkown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm(copy), target_(copy.target_)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::beExecuted(void) const
{
	std::srand(std::time(0));
	if (std::rand() % 2)
		throw RobotomyRequestForm::DrillFailureException();
	std::cout << target_ << " was succesfully robotomized." << std::endl;	
}

const char * RobotomyRequestForm::DrillFailureException::what() const throw()
{
	return ("Error: Robotomization failed");
}