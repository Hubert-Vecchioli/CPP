/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:52:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 15:27:21 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Templates_fct.hpp"

int main(void)
{
	int foo [5] = { 16, 2, 77, 40, 12071 };
	char str[] = "abcde";
	

	iter<char>(str, 5, addOne<char>);
	iter<int>(foo, 5, addOne<int>);
	std::cout << "[" << foo[0] << "] " << std::endl;
	std::cout << "[" << str[0] << "] " << std::endl;


}