/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:42:36 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 11:36:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	Data		*ptr;
	Data		*deserialized;
	uintptr_t	serialized;

	data.num = 1234;
	data.isValid = true;
	ptr = &data;
	std::cout << "Data bool value: " << ptr->isValid << std::endl;
	std::cout << "Data int value: " << ptr->num << std::endl;
	std::cout << "Data address: " << ptr << std::endl;
	serialized = Serializer::serialize(ptr);
	std::cout << "Raw address: " << serialized << std::endl;
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Deserialized int value: " << deserialized->num << std::endl;
	std::cout << "Deserialized bool value: " << deserialized->isValid << std::endl;
	std::cout << "Change value from deserialized to 21" << std::endl;
	deserialized->num = 21;
	std::cout << "Data value: " << ptr->num << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;

	return (0);
}