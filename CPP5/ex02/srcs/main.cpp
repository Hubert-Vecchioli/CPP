/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:35:00 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:41:39 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	bureaucrat = Bureaucrat("Obi-Wan", 2);

	ShrubberyCreationForm	form1 = ShrubberyCreationForm("Monty");
	RobotomyRequestForm		form2 = RobotomyRequestForm("RobotCop");
	PresidentialPardonForm	form3 = PresidentialPardonForm("Anakin");
	
	bureaucrat.executeForm(form1);
	bureaucrat.signForm(form1);
	bureaucrat.executeForm(form1);
	std::cout << std::endl;

	PresidentialPardonForm	form4 = form3;
	bureaucrat.signForm(form4);
	bureaucrat.executeForm(form4);
	bureaucrat.signForm(form4);
	std::cout << std::endl;

	bureaucrat.executeForm(form2);
	bureaucrat.signForm(form2);
	bureaucrat.executeForm(form2);
	return (0);
}