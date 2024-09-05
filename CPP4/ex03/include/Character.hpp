/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:24:15 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 15:30:46 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static const int inventorySize_ = 4;
		std::string	name_;

	public:
		AMateria	*inventory[inventorySize_];

		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character();

		Character & operator=(Character const &src);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif