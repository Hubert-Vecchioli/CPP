/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:20:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:59:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type_;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);
		AMateria & operator=(AMateria const &src);

		std::string const & getType() const; 

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif