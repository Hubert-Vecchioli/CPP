/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:04:49 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:04:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif