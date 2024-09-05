/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:28:37 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 15:35:40 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}
	{
		std::cout << "my try:" << std::endl;

		IMateriaSource* src = new MateriaSource();
		AMateria *	c1 = new Cure();
		AMateria *	i1 = new Ice();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		ICharacter* jedi = new Character("Obi-wan");
	
		jedi->equip(c1);
		jedi->equip(i1);

		jedi->use(0, *jedi);
		jedi->use(1, *jedi);
		jedi->unequip(0);
		jedi->use(0, *jedi);
		jedi->use(1, *jedi);

		jedi->use(30, *jedi); 
		jedi->use(-30, *jedi); 
		jedi->unequip(57527057);

		delete src;
		delete jedi;
		delete c1;
	}
	return (0);
}
