/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/23 14:25:01 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include "Weapon.class.hpp"

class HumanB
{
	private:
		std::string name_;
		Weapon *weapon_;
	public:
		HumanB( std::string name );
		~HumanB(void);
		void setWeapon( Weapon &weapon );
		void attack( void );
};
#endif