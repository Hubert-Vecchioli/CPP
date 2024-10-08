/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 11:47:08 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string name_;
	unsigned int hitPoint_;
	unsigned int energyPoint_;
	unsigned int attackDamage_;
	
	ClapTrap(void);
public:
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & rhs);

	unsigned int	getAttackDamage( void ) const;
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif