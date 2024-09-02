/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:00:02 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/25 13:56:58 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.class.hpp"

File::File(std::string name): name_(name)
{
	this->fstrm_.open(this->name_);
	if (!this->fstrm_.is_open())
	{
		std::cout << "Error: impossible to open file." << std::endl;
		exit(1);
	}
	return ;
}

File::~File(void)
{
	this->fstrm_.close();
}

void File::replace( std::string s1, std::string s2)
{
	std::string		line;
	std::ofstream	replace_file;
	size_t			pos;

	if (std::getline(this->fstrm_, line))
	{
		replace_file.open((this->name_ + ".replace"));
		if (!replace_file.is_open())
		{
			std::cerr << "Error: impossible to open the replace file." << std::endl;
			this->fstrm_.close();
			exit(1);
		}
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		replace_file << line;
		replace_file.close();
	}
}