/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:22:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:14 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat & Bureaucrat::operator++(void)
{
	//Exception
	this->grade_++;
	return (*this);
}

Bureaucrat & Bureaucrat::operator--(void)
{
	//Exception
	this->grade_--;
	return (*this);
}