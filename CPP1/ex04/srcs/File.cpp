/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:00:02 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 15:59:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string name): name_(name)
{
	this->fstrm_.open(this->name_.c_str());
	if (!this->fstrm_.is_open())
	{
		std::cout << "Error: impossible to open file." << std::endl;
		exit(1);
	}
	return ;
}

File::~File(void)
{
	if (this->fstrm_.is_open())
		this->fstrm_.close();
}

void File::replace( std::string s1, std::string s2)
{
	std::string		line;
	std::ofstream	replace_file;
	size_t			pos;


	if (!this->fstrm_.is_open())
	{
		std::cerr << "Error: file not open." << std::endl;
		exit(1);
	}
	if (std::getline(this->fstrm_, line, '\0'))
	{
		replace_file.open((this->name_ + ".replace").c_str());
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