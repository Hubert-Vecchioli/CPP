/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:35:00 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 15:41:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat	bureaucrat = Bureaucrat("Obi-Wan", 2);
		Intern	intern = Intern();
		
		try {
			AForm	*form1 = intern.makeForm("shrubbery request", "Monty");
			AForm	*form2 = intern.makeForm("robotomy request", "Bender");
			AForm	*form3 = intern.makeForm("presidentialpardon request", "Anakin");
			
			bureaucrat.executeForm(*form1);
			bureaucrat.signForm(*form1);
			bureaucrat.executeForm(*form1);
			std::cout << std::endl;

			bureaucrat.signForm(*form3);
			bureaucrat.executeForm(*form3);
			bureaucrat.signForm(*form3);
			std::cout << std::endl;

			bureaucrat.executeForm(*form2);
			bureaucrat.signForm(*form2);
			bureaucrat.executeForm(*form2);
			delete form1;
			delete form2;
			delete form3;
			intern.makeForm("random failure", "new_intern");
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

	