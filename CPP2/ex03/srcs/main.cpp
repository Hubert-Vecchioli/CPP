/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 22:07:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	std::cout << "Point in the triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 100), Point(100, 0), Point(10, 10))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
	std::cout << "Point out of the triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 100), Point(100, 0), Point(100, 100))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
	std::cout << "Point on a corner of the triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 100), Point(100, 0), Point(0, 100))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
	std::cout << "Point on a side of the triangle" << std::endl;
	if (bsp(Point(0, 0), Point(0, 100), Point(100, 0), Point(0, 10))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
    std::cout << "Triangle with float coordinates" << std::endl;
    if (bsp(Point(0.5f, 0.5f), Point(1.5f, 0.5f), Point(0.5f, 2.5f), Point(0.5f, 0.25f))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
    std::cout << "Triangle with combination of integer and float coordinates" << std::endl;
    if (bsp(Point(0.5f, 0), Point(0.5f, 100), Point(97.89f, 0), Point(-35.0f, 48.5f))) {
        std::cout << "->Point is in the triangle" << std::endl;
    } else {
        std::cout << "->Point is not in the triangle" << std::endl;
    }
	return (0);
}