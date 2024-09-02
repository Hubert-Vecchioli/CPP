/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:32:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/23 14:25:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include "Weapon.class.hpp"

class HumanA
{
	private:
		std::string name_;
		Weapon &weapon_;
	public:
		HumanA( std::string name,  Weapon &weapon);
		~HumanA(void);
		void attack( void );
};
#endif