/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 14:46:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class File
{
private:
	std::string name_;
	std::ifstream fstrm_;
public:
	File(std::string name);
	~File(void);

	void replace(std::string s1, std::string s2);
};

#endif