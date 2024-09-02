/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:58:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:56:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	main(int ac, char** av)
{
	if (ac != 4)
	{
        std::cout << "Wrong input, enter a filename, a str 'to_find' to be replaced by 'to_replace'" << std::endl;
        return (1);
    }
	else
	{
        File	file(av[1]);
        file.replace(av[2], av[3]);
    }
    return (0);
}