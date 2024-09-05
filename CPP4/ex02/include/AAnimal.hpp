/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:25:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 11:27:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class AAnimal
{
	protected:
		std::string type_;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);
		AAnimal & operator=(AAnimal const & rhs);

		virtual void makeSound(void) const = 0;	
		std::string getType(void) const;	
		virtual Brain *getBrain(void) const = 0;
};

#endif