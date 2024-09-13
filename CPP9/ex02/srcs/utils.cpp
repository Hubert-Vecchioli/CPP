/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:47:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/13 01:58:31 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <list>

template <typename T>
void mergeInsertionSort(T& container)
{
    if (container.size() <= 1)
        return;

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

    mergeInsertionSort(small);

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

    container = small;
}


template <typename T, typename F>
void iter(T &container, unsigned int max, F function)
{
    unsigned int i = 0;
    for (typename T::iterator it = container.begin(); it != container.end(); ++it, ++i)
    {
        if (i > max)
        {
            std::cout << " [...]";
            return;
        }
        function(*it);
    }
}


template <typename W>
void print_info(W & number)
{
	std::cout << " " << number;
	return ;
}
