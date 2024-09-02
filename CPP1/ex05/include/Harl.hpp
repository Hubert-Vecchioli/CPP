/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 16:28:40 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <cstdlib>

class Harl
{
private:
	void debug_( void );
	void info_( void );
	void warning_( void );
	void error_( void );
public:
	Harl(void);
	~Harl(void);
	void complain( std::string level );
};

#endif