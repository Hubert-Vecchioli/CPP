/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:31 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:51 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>


class Bureaucrat
{
	private:
		std::string name_;
		int grade_;
		Bureaucrat(void);
	public:
		Bureaucrat(int grade);
		Bureaucrat(std::string const &name);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &src);
		std::string getName(void) const;
		int getGrade(void) const;
		Bureaucrat & operator++(void);
		Bureaucrat & operator--(void);
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif