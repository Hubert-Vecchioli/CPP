/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:22:11 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:03:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &src);
		virtual ~Cure();

		Cure & operator=(Cure const &src);

		Cure * clone() const;
		void use(ICharacter& target);
};

#endif