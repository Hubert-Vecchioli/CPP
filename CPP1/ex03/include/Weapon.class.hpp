/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/23 14:17:41 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>

class Weapon
{
	private:
		std::string type_;
	public:
		Weapon( std::string type );
		~Weapon(void);
		const std::string &getType(void) const;
		void setType( std::string type );
};
#endif