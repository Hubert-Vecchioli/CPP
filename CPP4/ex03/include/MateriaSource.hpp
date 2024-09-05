/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:13:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:14:23 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static int const materiaSize_ = 4;
		AMateria *materia_[materiaSize_];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource();

		MateriaSource & operator=(MateriaSource const &src);

		void learnMateria(AMateria * materia);
		AMateria* createMateria(std::string const & type);
};

#endif