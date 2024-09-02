/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:08:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/22 10:08:08 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.class.hpp>

Zombie *zombieHorde( int N, std::string name);

int main(void)
{
    int N = 10;
    Zombie *zombies = zombieHorde(N, "Paul");
    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }
    delete [] zombies;
    return 0;
}