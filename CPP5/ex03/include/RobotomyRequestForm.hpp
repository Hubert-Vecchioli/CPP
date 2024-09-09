/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:11:54 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:36:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const	target_;
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		void beExecuted(void) const;

		class DrillFailureException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif