/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:41:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 11:37:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const &src)
{
	(void)src;
}

Serializer::~Serializer(void)
{
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data		*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}