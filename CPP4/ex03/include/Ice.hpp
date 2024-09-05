/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:22:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:49:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
class AMateria;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &src);
		virtual ~Ice();

		Ice & operator=(Ice const &);

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif