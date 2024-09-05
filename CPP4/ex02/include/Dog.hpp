/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:25:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 12:10:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
	private:
		Brain *brain_;
	public:
		Dog(void);
		Dog(Dog const & src);
		virtual ~Dog(void);
		Dog & operator=(Dog const & rhs);
		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif