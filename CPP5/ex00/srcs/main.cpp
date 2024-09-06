/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:35:00 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 00:57:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat teacher_a = Bureaucrat("Obi-Wan", 150);
	std::cout << teacher_a << std::endl;
	try {
		teacher_a.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		teacher_a.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	Bureaucrat teacher_b = Bureaucrat("Anakin", 1);
	std::cout << teacher_b << std::endl;
	try {
		teacher_b.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}