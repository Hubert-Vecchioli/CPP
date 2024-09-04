/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/04 18:01:44 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "type: "<< j->getType() << " " << std::endl;
		std::cout << "type: "<< i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta2 = new WrongAnimal();
		const WrongAnimal* i2 = new WrongCat();
		std::cout << "type: "<< i2->getType() << " " << std::endl;
		i2->makeSound();
		meta2->makeSound();
		delete meta2;
		delete i2;
	}
	return 0;
}