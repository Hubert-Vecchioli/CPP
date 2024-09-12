/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>  // Pour les itérateurs
#include <list>      // Peut être adapté pour n'importe quel conteneur séquentiel comme std::vector

template <typename T>
void mergeInsertionSort(T& container)
{
    if (container.size() <= 1)
        return;

    // Séparation des éléments en paires
    T small, large;
    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        typename T::value_type first = *it;
        ++it;
        if (it != container.end())
        {
            typename T::value_type second = *it;
            if (first < second)
            {
                small.push_back(first);
                large.push_back(second);
            }
            else
            {
                small.push_back(second);
                large.push_back(first);
            }
            ++it;
        }
        else
        {
            small.push_back(first);
        }
    }

    // Tri des petites valeurs avec insertion récursive
    mergeInsertionSort(small);

    // Insertion des grandes valeurs dans les bonnes positions
    typename T::iterator large_it = large.begin();
    while (large_it != large.end())
    {
        typename T::iterator pos = small.begin();
        while (pos != small.end() && *pos <= *large_it)
        {
            ++pos;
        }
        small.insert(pos, *large_it);
        ++large_it;
    }

    // Remettre la liste triée dans le conteneur original
    container = small;
}